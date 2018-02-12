/*===================================================================================*//**
	PlayerCharacter
	
	Prefab class for the player character.
    
    Copyright 2017 Erick Fernandez de Arteaga. All rights reserved.
        https://www.linkedin.com/in/erick-fda
        https://bitbucket.org/erick-fda
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "PlayerCharacter.h"
#include "CharacterController.h"
#include "Inventory.h"
#include "Sender.h"
#include "Receiver.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
PlayerCharacter::PlayerCharacter() :
	SimpleSprite("IceTile.png", 0, 0)
{
	addComponent<CharacterController*>(new CharacterController(this));
	addComponent<Inventory*>(new Inventory(this));
	addComponent<Sender*>(new Sender(this, std::to_string(this->getId())));
	addComponent<Receiver*>(new Receiver(this, std::to_string(this->getId())));
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

