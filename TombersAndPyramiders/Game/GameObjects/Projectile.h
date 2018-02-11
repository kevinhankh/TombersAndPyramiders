/*===================================================================================*//**
	Projectile
	
	A Damaging region that is fired by a projectile weapon, moves, and destroys itself 
	after a set duration or after hitting something.
    
    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "DamagingRegion.h"

/*========================================================================================
	Projectile	
========================================================================================*/
class Projectile : public DamagingRegion
{
	/*----------------------------------------------------------------------------------------
		Resource Management
	----------------------------------------------------------------------------------------*/
	explicit Projectile() = delete;

	explicit Projectile(BaseWeapon* weapon, string imageName, float colliderWidth, float colliderHeight);

	virtual ~Projectile();
};
