#include "HostCharacter.h"
#include "CharacterController.h"
#include "Inventory.h"
#include "Receiver.h"

HostCharacter::HostCharacter(BasePilot* basePilot, int networkingID) :
	Character(basePilot)
{
	std::shared_ptr<Receiver> receiver = addComponent<Receiver>(this, std::to_string(networkingID));
	receiver->Subscribe("ATTACK", [](std::map<std::string, void*> data) -> void 
	{
		((HostCharacter*)data["this"])->getComponent<CharacterController>()->useWeapon();
	}, this);

	receiver->Subscribe("TRIGGER", [](std::map<std::string, void*> data) -> void
	{
		if (!((HostCharacter*)data["this"])->getComponent<CharacterController>()->tryInvokeTrigger())
		{
			std::cout << "Sync Error on character receiving Trigger event. Should only be called on successful triggering, however receiver could not invoke a trigger." << std::endl;
		}
	}, this);
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
void HostCharacter::onUpdate(int ticks)
{
	updateFrames(ticks);
}
