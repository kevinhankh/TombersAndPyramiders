/*===================================================================================*//**
	BaseProjectileWeapon

	Abstract class for a base projectile weapon.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseProjectileWeapon.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseProjectileWeapon::BaseProjectileWeapon(int damage, std::string projectileImageName,
	Vector2 projectileColliderSize, bool destroyProjectilesOnCollision, float attackCooldownTime, 
	Vector2 projectileSpawnOffsetFromHolder,
	float projectileSpriteScale, Vector2 projectileVelocity, float projectileLifespan) :
	BaseWeapon(damage, attackCooldownTime),
	m_projectileImageName{ projectileImageName }, 
	m_projectileColliderSize{ projectileColliderSize }, 
	m_destroyProjectilesOnCollision{ destroyProjectilesOnCollision }, 
	m_projectileSpawnOffsetFromHolder{ projectileSpawnOffsetFromHolder }, 
	m_projectileSpriteScale{ projectileSpriteScale }, 
	m_projectileVelocity{ projectileVelocity }, 
	m_projectileLifespan{ projectileLifespan }
{}


/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseProjectileWeapon::setOwnerId(int id)
{}
