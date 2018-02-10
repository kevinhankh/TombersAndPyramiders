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
#include "DummyPlayerCharacter.h"
#include "CharacterController.h"
#include "Inventory.h"

/*----------------------------------------------------------------------------------------
Resource Management
----------------------------------------------------------------------------------------*/
DummyPlayerCharacter::DummyPlayerCharacter() :
	SimpleSprite("Dummy.png", 0, 0)
{
	addComponent<CharacterController*>(new CharacterController(this));
	addComponent<Inventory*>(new Inventory(this));
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

void DummyPlayerCharacter::onUpdate(int ticks) {


	/*if (m_boxCollider != nullptr && m_boxCollider->collisionDetected()) {

	}
	else {
		this->getTransform()->addX(0.15f);
	}*/
}