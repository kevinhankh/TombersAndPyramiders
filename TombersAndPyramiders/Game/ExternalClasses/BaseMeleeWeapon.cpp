/*===================================================================================*//**
	BaseMeleeWeapon

	Abstract class for a base melee weapon.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseMeleeWeapon.h"
#include "DamagingRegion.h"
#include "Inventory.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseMeleeWeapon::BaseMeleeWeapon(string imageName, float colliderWidth, float colliderHeight, 
	float xOffsetFromHolder, float yOffsetFromHolder) :
	m_damagingRegion{ this, imageName, colliderWidth, colliderHeight }
{
	m_offsetFromHolder = Vector2(xOffsetFromHolder, yOffsetFromHolder);
}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseMeleeWeapon::updatePosition()
{
	if (owner() != nullptr)
	{
		float newX = owner()->getTransform()->getX() + m_offsetFromHolder.getX();
		float newY = owner()->getTransform()->getY() + m_offsetFromHolder.getY();
		
		m_damagingRegion.getTransform()->setPosition(newX, newY);
	}
}
