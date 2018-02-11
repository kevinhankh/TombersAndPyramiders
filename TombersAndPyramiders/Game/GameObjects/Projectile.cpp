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
#include "BaseItem.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
Projectile::Projectile(BaseWeapon* weapon, string imageName, float colliderWidth, float colliderHeight, 
	float spawnXPosition, float spawnYPosition, float spriteScale, float lifespan) :
	DamagingRegion{ weapon, imageName, colliderWidth, colliderHeight, spawnXPosition, spawnYPosition, spriteScale }, 
	m_lifespan{ lifespan }
{}

Projectile::~Projectile()
{}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void Projectile::onUpdate(int ticks)
{
	updateLifespan(ticks);
}

void Projectile::updateLifespan(int ticks)
{
	m_lifespan -= ticks / BaseItem::TICKS_PER_SECOND;

	if (m_lifespan <= 0)
	{
		//GameObject::destroy(this); // TODO: Destroy projectile without a memory access violation.
	}
}
