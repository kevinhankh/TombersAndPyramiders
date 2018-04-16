/*===================================================================================*//**
	BaseHelmet
	
	Abstract class for a base helmet.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include <stdexcept>
#include "BaseHelmet.h"
#include "Inventory.h"
#include "Randomize.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const float BaseHelmet::WOODEN_HELMET_CRITICAL_RESIST_CHANCE = 0.05f;
const float BaseHelmet::SILVER_HELMET_CRITICAL_RESIST_CHANCE = 0.2f;
const float BaseHelmet::GOLD_HELMET_CRITICAL_RESIST_CHANCE = 0.5f;

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseHelmet::BaseHelmet(float criticalResistChance) :
	m_criticalResistChance{ criticalResistChance }
{
	if (m_criticalResistChance < 0)
	{
		throw std::invalid_argument("BaseHelmet::BaseHelmet(): m_criticalResistChance must be non-negative.");
	}
}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
bool BaseHelmet::doesAvoidCriticalHit()
{
	return (Randomize::RandomFloat(0, 1) < m_criticalResistChance);
}

void BaseHelmet::setProperties(float criticalResistChance)
{
	m_criticalResistChance = criticalResistChance;
}

std::shared_ptr<BaseItem> BaseHelmet::addSubclassToInventory()
{
	return m_inventory->setHelmet(shared_from_this());
}
