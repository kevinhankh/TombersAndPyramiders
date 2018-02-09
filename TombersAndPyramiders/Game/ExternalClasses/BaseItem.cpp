/*===================================================================================*//**
	BaseItem
	
	Abstract class for an item that can be carried in an Inventory.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseItem.h"
#include "Inventory.h"

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseItem::addToInventory(Inventory* inventory)
{
	m_inventory = inventory;
}

GameObject* BaseItem::owner()
{
	return (m_inventory == nullptr) ? nullptr : m_inventory->getGameObject();
}
