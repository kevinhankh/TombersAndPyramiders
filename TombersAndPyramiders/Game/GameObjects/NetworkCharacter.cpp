#include "NetworkCharacter.h"
#include "CharacterController.h"
#include "Inventory.h"
#include "Receiver.h"
#include "Sender.h"

NetworkCharacter::NetworkCharacter(BasePilot* basePilot, int networkingID) :
	Character(basePilot)
{
	setFPS(12);
	addComponent<Inventory>(this);
	addComponent<Sender> (this, std::to_string (networkingID));
	addComponent<Receiver>(this, std::to_string (networkingID));
}

/*----------------------------------------------------------------------------------------
Instance Getter Methods
----------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------
Instance Setter Methods
----------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------
Instance Methods
----------------------------------------------------------------------------------------*/
void NetworkCharacter::onUpdate(int ticks)
{
	updateFrames(ticks);
}