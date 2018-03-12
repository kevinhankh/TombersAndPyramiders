/*===================================================================================*//**
	BaseShield
	
	Abstract class for a base shield.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseShield.h"
#include "Inventory.h"

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
BaseShield::BaseShield() :
	m_isBlocking{ false }, 
	m_defense{ 5 }, 
	m_blockCooldownTime{ 0.75 }
{}

std::shared_ptr<BaseItem> BaseShield::addSubclassToInventory()
{
	return m_inventory->setShield(shared_from_this());
}

bool BaseShield::use()
{
	auto willBlock = !m_isBlocking;

	if (willBlock)
	{
		onStart();
	}

	return willBlock;
}

void BaseShield::onStart()
{
	m_isBlocking = true;
	m_timeUntilNextBlock = m_blockCooldownTime;

	//m_damagingRegion->clearHitList();
	//m_damagingRegion->getTransform()->setScale(1);
	//m_damagingRegion->getComponent<BoxCollider>()->setDisabled(false);
}

void BaseShield::onUpdate(int ticks)
{

}

void BaseShield::onEnd()
{

}

bool BaseShield::isBlocking()
{
	return m_isBlocking;
}
