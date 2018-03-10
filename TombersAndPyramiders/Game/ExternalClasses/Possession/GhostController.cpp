#include "GhostController.h"

GhostController::GhostController(GameObject* parentGameobject, BasePilot* pilot) : BaseController(parentGameobject, pilot)
{
	m_movementSpeed.setX(0.15f);
	m_movementSpeed.setY(0.15f);
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
