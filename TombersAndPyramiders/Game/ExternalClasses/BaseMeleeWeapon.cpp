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

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseMeleeWeapon::BaseMeleeWeapon(float colliderWidth, float colliderHeight, 
	float xOffsetFromHolder, float yOffsetFromHolder) :
	m_damagingRegion{ this, colliderWidth, colliderHeight }
{}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseMeleeWeapon::onUpdate(int ticks)
{

}
