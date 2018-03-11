#include "GhostController.h"
#include "BasePossessableController.h"
#include "GhostCharacter.h"

GhostController::GhostController(GameObject* parentGameobject, BasePilot* pilot) : BaseController(parentGameobject, pilot)
{
	m_movementSpeed.setX(0.15f);
	m_movementSpeed.setY(0.15f);
	m_toFollow = nullptr;
}

void GhostController::onStart()
{
	std::cout << "GhostController::OnStart" << std::endl;
}

void GhostController::onUpdate(int ticks)
{
	if (m_pilot != nullptr)
	{
		m_pilot->onUpdate(ticks);
	}
	if (m_toFollow != nullptr)
	{
		gameObject->getTransform()->setPosition(m_toFollow->getGameObject()->getTransform()->getX(), m_toFollow->getGameObject()->getTransform()->getY());
	}
}

void GhostController::possess(std::shared_ptr<BasePossessableController> toPossess)
{
	follow(toPossess);
	GhostCharacter* ghost = dynamic_cast<GhostCharacter*>(gameObject);
	if (ghost != nullptr)
	{
		ghost->setMode(GhostCharacter::Mode::possessing);
	}
}

void GhostController::stopPossessing()
{
	follow(nullptr);
	GhostCharacter* ghost = dynamic_cast<GhostCharacter*>(gameObject);
	if (ghost != nullptr)
	{
		ghost->setMode(GhostCharacter::Mode::ghost);
	}
}

void GhostController::follow(std::shared_ptr<BasePossessableController>  toFollow)
{
	m_toFollow = toFollow;
}

void GhostController::move(Vector2 delta)
{
	delta.setX(delta.getX() * m_movementSpeed.getX());
	delta.setY(delta.getY() * m_movementSpeed.getY());

	if (delta.getMagnitude() == 0)
	{
	}
	else
	{
		gameObject->getTransform()->setRotation(delta.getRotationInDegrees());
	}

	gameObject->getTransform()->addTranslation(delta.getX(), delta.getY());
}
