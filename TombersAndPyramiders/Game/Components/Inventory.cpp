/*===================================================================================*//**
	Inventory
	
	A component representing a collection of items owned by a GameObject.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "Inventory.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
Inventory::Inventory(GameObject* gameobject) :
	Inventory(gameObject, nullptr, nullptr, nullptr, nullptr, nullptr)
{}

Inventory::Inventory(GameObject* gameobject, BaseWeapon* weapon, BaseShield* shield, BaseHelmet* helmet,
	BaseChestplate* chestplate, BaseGreaves* greaves) :
	Component(gameObject)

{}

/*----------------------------------------------------------------------------------------
	Instance Getter Methods
----------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------
	Instance Setter Methods
----------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void Inventory::onStart()
{};

void Inventory::onUpdate(int ticks)
{};

void Inventory::onEnd()
{};
