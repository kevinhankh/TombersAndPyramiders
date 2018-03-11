#include "BoulderController.h"
#include "Rigidbody.h"
#include "SharedConstants.h"
#include "GameManager.h"
#include "DamagingRegion.h"

const float BoulderController::MAX_MOVESPEED = 0.8f;
const float BoulderController::FRICTION = 0.95f;
const float BoulderController::COOLDOWN = 3000.0f;

BoulderController::BoulderController(GameObject* parentGameobject, BasePilot* pilot) : BasePossessableController(parentGameobject, pilot) {
	m_cooldownTicker = 0.0f;
}

void BoulderController::onPossessionStart()
{
	m_rigidBody = gameObject->getComponent<Rigidbody>();
	if (m_rigidBody != nullptr)
	{
		m_rigidBody->setFrictionCoefficient(FRICTION);
	}
}

void BoulderController::onPossessionEnd()
{
	m_rigidBody = nullptr;
}

void BoulderController::move(Vector2 direction)
{
	if (m_rigidBody != nullptr && direction.getMagnitude() > 0)
	{
		direction.normalize();
		if (m_rigidBody->getVelocity().getMagnitude() < MAX_MOVESPEED)
		{
			Vector2 velocity = Vector2(direction.getX() / 200.0f, direction.getY() / 200.0f);
			m_rigidBody->addVelocity(velocity);
		}
	}
	m_cooldownTicker -= FRAME_RATE;

	if (m_damagingRegion != nullptr)
	{
		if (COOLDOWN - m_cooldownTicker >= 1000)
		{
			destroy(m_damagingRegion->getId());
			m_damagingRegion = nullptr;
		}
		else
		{
			//Where infront from non-rotation object
			Vector2 dirMoving = Vector2(m_rigidBody->getVelocity().getX(), m_rigidBody->getVelocity().getY());
			dirMoving.normalize();
			float newX = gameObject->getTransform()->getX() + dirMoving.getX() / 2.0f;
			float newY = gameObject->getTransform()->getY() + dirMoving.getY() / 2.0f;
			Vector2 newPosition = Vector2(newX, newY);
			//Rotate around
			newPosition.rotateFromOrigin(Vector2(gameObject->getTransform()->getX(), gameObject->getTransform()->getY()), gameObject->getTransform()->getRotation());
			//Set position/rotation
			m_damagingRegion->getTransform()->setPosition(newPosition.getX(), newPosition.getY());
			m_damagingRegion->getTransform()->setRotation(gameObject->getTransform()->getRotation());
		}
	}
}

void BoulderController::trigger(Vector2 direction)
{
	if (m_cooldownTicker <= 0.0f && m_rigidBody != nullptr)
	{
		m_rigidBody->addVelocity(m_rigidBody->getVelocity());
		m_rigidBody->addVelocity(m_rigidBody->getVelocity());
		m_rigidBody->addVelocity(m_rigidBody->getVelocity());
		m_cooldownTicker = COOLDOWN;
		if (m_damagingRegion == nullptr)
		{
			auto collider = gameObject->getComponent<BoxCollider>();
			m_damagingRegion = GameManager::getInstance()->createGameObject<DamagingRegion>(false, "IceTile.png", collider->getWidth(), collider->getHeight(), 0, 0, gameObject->getTransform()->getScale());
		}
	}
}