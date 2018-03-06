#include "GhostPilot.h"
#include "InputManager.h"
#include "Vector2.h"
#include "BaseController.h"
#include "GameManager.h"

void GhostPilot::onStart()
{
	m_possessableController = nullptr;
	m_ghostController = m_controller;
}

void GhostPilot::onUpdate(int ticks)
{
	if (m_possessableController != nullptr)
	{
		//Possessing + Space = Trigger
		if (InputManager::getInstance()->onKeyPressed(SDLK_SPACE))
		{
			m_possessableController->trigger();
		}
		//Possessing + E = Stop Possessing
		else if (InputManager::getInstance()->onKeyPressed(SDLK_e))
		{
			m_possessableController->onPossessionEnd();
			m_controller->setPilot(nullptr);
			m_possessableController = nullptr;
			m_possessing = false;
			m_ghostController->setPilot(this);
		}
	}
	else
	{
		if (m_controller != nullptr) //Regular controller for moving the Ghost
		{
			//Not Possessing + Movement = Move Ghost
			Transform* transform = m_controller->getGameObject()->getTransform();
			Vector2 movement = getMovement();
			transform->addTranslation(movement.getX(), movement.getY());

			//Not Possessing + E = Try To Possess
			if (InputManager::getInstance()->onKeyPressed(SDLK_e))
			{
				std::vector<std::shared_ptr<GameObject>> gameObjects = GameManager::getInstance()->getObjectsInBounds(transform->getX(), transform->getY(), 2.0f, 2.0f);
				for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
				{
					std::shared_ptr<BasePossessableController> possessionController = (*it)->getComponent<BasePossessableController>();
					if (possessionController != nullptr) //If we pressed E on something we can possess
					{
						m_controller->setPilot(nullptr);
						possessionController->onPossessionStart(this);
						m_possessableController = possessionController;
						break;
					}
				}
					
			}
		}
	}
}

void GhostPilot::onEnd()
{}

Vector2 GhostPilot::getMovement()
{
	Vector2 movement = Vector2(0, 0);

	/* Move up. */
	if (InputManager::getInstance()->onKey(SDLK_w))
	{
		movement.setY(movement.getY() + 1);
	}

	/* Move down. */
	if (InputManager::getInstance()->onKey(SDLK_s))
	{
		movement.setY(movement.getY() - 1);
	}

	/* Move left. */
	if (InputManager::getInstance()->onKey(SDLK_a))
	{
		movement.setX(movement.getX() - 1);
	}

	/* Move right. */
	if (InputManager::getInstance()->onKey(SDLK_d))
	{
		movement.setX(movement.getX() + 1);
	}

	return movement;
}

