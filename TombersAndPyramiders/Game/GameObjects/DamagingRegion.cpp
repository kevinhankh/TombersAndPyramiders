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
DamagingRegion::DamagingRegion(float colliderWidth, float colliderHeight) :
	GameObject(false)
{
	if (colliderWidth <= 0)
	{
		throw std::invalid_argument("DamagingRegion::DamagingRegion(): colliderWidth must be greater than zero.");
	}

	if (colliderHeight <= 0)
	{
		throw std::invalid_argument("DamagingRegion::DamagingRegion(): colliderHeight must be greater than zero.");
	}

	addComponent<BoxCollider*>(new BoxCollider(this, colliderWidth, colliderHeight));
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

