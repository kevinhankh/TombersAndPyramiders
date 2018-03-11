#include "BoulderController.h"
#include "Rigidbody.h"
#include "SharedConstants.h"

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
		std::cout << m_rigidBody->getVelocity().getMagnitude() << std::endl;
	}
	m_cooldownTicker -= FRAME_RATE;
}

void BoulderController::trigger(Vector2 direction)
{
	if (m_cooldownTicker <= 0.0f && m_rigidBody != nullptr)
	{
		m_rigidBody->addVelocity(m_rigidBody->getVelocity());
		m_rigidBody->addVelocity(m_rigidBody->getVelocity());
		m_rigidBody->addVelocity(m_rigidBody->getVelocity());
		m_cooldownTicker = COOLDOWN;
	}
}