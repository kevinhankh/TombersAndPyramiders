#include "NetworkCharacter.h"
#include "CharacterController.h"
#include "Inventory.h"
#include "Receiver.h"

NetworkCharacter::NetworkCharacter() :
	SimpleSprite("IceTile.png", 0, 0)
{
	//addComponent<CharacterController*>(new CharacterController(this));
	addComponent<Inventory*>(new Inventory(this));
	addComponent<Receiver*>(new Receiver(this, std::to_string(this->getId())));
}