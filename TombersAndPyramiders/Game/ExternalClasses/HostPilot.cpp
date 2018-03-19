#include "HostPilot.h"
#include "CharacterController.h"
#include "InputManager.h"
#include "Vector2.h"

void HostPilot::setController(BaseController* controller)
{
	BasePilot::setController(controller);

	/* Store a correctly typed pointer to the controller for convenience. */
	m_characterController = static_cast<CharacterController*>(controller);
}

/*----------------------------------------------------------------------------------------
Instance Methods
----------------------------------------------------------------------------------------*/
void HostPilot::onStart()
{}

void HostPilot::onUpdate(int ticks)
{
	
	if (m_characterController != nullptr)
	{
		m_characterController->move(getMovement());
	}
	/*
	if (getWeaponInput())
	{
		m_characterController->useWeapon();
	}
	*/
}

void HostPilot::onEnd()
{}

Vector2 HostPilot::getMovement()
{
	return m_lastNetworkVector;
}

bool HostPilot::getWeaponInput()
{
	return false;
}
