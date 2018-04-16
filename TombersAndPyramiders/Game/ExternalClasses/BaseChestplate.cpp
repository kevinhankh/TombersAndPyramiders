/*===================================================================================*//**
	BaseChestplate
	
	Abstract class for a base chestplate

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseChestplate.h"
#include "Inventory.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const float BaseChestplate::WOODEN_CHESTPLATE_DAMAGE_MULTIPLIER = 0.95;
const float BaseChestplate::SILVER_CHESTPLATE_DAMAGE_MULTIPLIER = 0.85;
const float BaseChestplate::GOLD_CHESTPLATE_DAMAGE_MULTIPLIER = 0.75;

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseChestplate::BaseChestplate(float damageMultiplier) :
	m_damageMultiplier{ damageMultiplier }
{

}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
int BaseChestplate::calculateRealDamage(int damage)
{
	return (int)((float)damage * m_damageMultiplier);
}

std::shared_ptr<BaseItem> BaseChestplate::addSubclassToInventory()
{
	return m_inventory->setChestplate(shared_from_this());
}
