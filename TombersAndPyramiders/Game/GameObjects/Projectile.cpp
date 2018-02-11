/*===================================================================================*//**
	Projectile
	
	A Damaging region that is fired by a projectile weapon, moves, and destroys itself 
	after a set duration or after hitting something.
    
    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "Projectile.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
Projectile::Projectile(BaseWeapon* weapon, string imageName, float colliderWidth, float colliderHeight) :
	DamagingRegion{ weapon, imageName, colliderWidth, colliderHeight }
{}

Projectile::~Projectile()
{}
