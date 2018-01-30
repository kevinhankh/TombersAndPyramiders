/*===================================================================================*//**
	Inventory
	
	A component representing a collection of items owned by a GameObject.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "Inventory.h"
#include "BaseItem.h"

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
void Inventory::addItem(BaseItem* item)
{
	item->addToInventory(this);
}

void Inventory::addWeapon(BaseWeapon* weapon)
{
	delete m_weapon;
	m_weapon = weapon;
}

void Inventory::addShield(BaseShield* shield)
{
	delete m_shield;
	m_shield = shield;
}

void Inventory::addHelmet(BaseHelmet* helmet)
{
	delete m_helmet;
	m_helmet = helmet;
}

void Inventory::addChestplate(BaseChestplate* chestplate)
{
	delete m_chestplate;
	m_chestplate = chestplate;
}

void Inventory::addGreaves(BaseGreaves* greaves)
{
	delete m_greaves;
	m_greaves = greaves;
}

void Inventory::onStart()
{};

void Inventory::onUpdate(int ticks)
{};

void Inventory::onEnd()
{};
