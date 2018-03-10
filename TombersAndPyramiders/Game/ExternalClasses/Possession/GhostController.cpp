#include "GhostController.h"

GhostController::GhostController(GameObject* parentGameobject, BasePilot* pilot) : BaseController(parentGameobject, pilot)
{
	m_movementSpeed.setX(0.15f);
	m_movementSpeed.setY(0.15f);
}

void GhostController::onStart()
{
}

void GhostController::onUpdate(int ticks)
{
	m_pilot.get()->onUpdate(ticks);
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
