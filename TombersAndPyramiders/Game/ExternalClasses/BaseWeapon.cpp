/*===================================================================================*//**
	BaseWeapon
	
	Abstract class for a base weapon.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseWeapon.h"
#include "Inventory.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseWeapon::BaseWeapon(float colliderWidth, float colliderHeight) :
	_damagingRegion{ DamagingRegion(colliderWidth, colliderHeight) }
{}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseWeapon::addToInventory(Inventory* inventory)
{
	inventory->setWeapon(this);
}
