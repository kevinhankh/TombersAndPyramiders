/*===================================================================================*//**
	DamagingRegion
	
	Prefab class for a GameObject that causes damage to damageable objects when it 
	collides with them.
    
    Copyright 2017 Erick Fernandez de Arteaga. All rights reserved.
        https://www.linkedin.com/in/erick-fda
        https://bitbucket.org/erick-fda
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include <stdexcept>
#include "DamagingRegion.h"
#include "BoxCollider.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
DamagingRegion::DamagingRegion(BaseWeapon* weapon, float colliderWidth, float colliderHeight) :
	SimpleSprite{ "IceTile.png", 0, 0, 0, 0.5 },
	_weapon{ weapon }
{
	if (_weapon == nullptr)
	{
		throw std::invalid_argument("DamagingRegion::DamagingRegion(): _weapon cannot be null.");
	}

	if (colliderWidth < 0)
	{
		throw std::invalid_argument("DamagingRegion::DamagingRegion(): colliderWidth must be non-negative.");
	}

	if (colliderHeight < 0)
	{
		throw std::invalid_argument("DamagingRegion::DamagingRegion(): colliderHeight must be non-negative.");
	}



	// TODO: Add this line back in once Michael fixes BoxCollider.
	//addComponent<BoxCollider*>(new BoxCollider(this, colliderWidth, colliderHeight));
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
void DamagingRegion::onUpdate(int ticks)
{

}
