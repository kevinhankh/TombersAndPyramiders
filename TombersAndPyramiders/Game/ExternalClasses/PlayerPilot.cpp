/*===================================================================================*//**
	PlayerPilot
	
	A pilot that gets local keyboard input from the player.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "PlayerPilot.h"
#include "CharacterController.h"

/*----------------------------------------------------------------------------------------
	Instance Setter Methods
----------------------------------------------------------------------------------------*/
void PlayerPilot::setController(BaseController* controller)
{
	BasePilot::setController(controller);

	/* Store a correctly typed pointer to the controller for convenience. */
	m_characterController = static_cast<CharacterController*>(controller);
}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void PlayerPilot::onStart()
{}

void PlayerPilot::onUpdate(int ticks)
{

}

void PlayerPilot::onEnd()
{}