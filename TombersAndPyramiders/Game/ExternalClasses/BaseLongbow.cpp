/*===================================================================================*//**
	BaseLongbow

	Abstract class for a base longbow.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseLongbow.h"
#include "Projectile.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const float BaseLongbow::LONGBOW_PROJECTILE_COLLIDER_WIDTH = 0.5;
const float BaseLongbow::LONGBOW_PROJECTILE_COLLIDER_HEIGHT = 0.5;
const float BaseLongbow::LONGBOW_PROJECTILE_SPRITE_SCALE = 0.5;
const float BaseLongbow::LONGBOW_PROJECTILE_SPAWN_X_OFFSET_FROM_HOLDER = 1;
const float BaseLongbow::LONGBOW_PROJECTILE_SPAWN_Y_OFFSET_FROM_HOLDER = 0;
const float BaseLongbow::LONGBOW_ATTACK_COOLDOWN_TIME = 5;

/*----------------------------------------------------------------------------------------
	Resource Methods
----------------------------------------------------------------------------------------*/
BaseLongbow::BaseLongbow(std::string projectileImageName) :
	BaseProjectileWeapon{ projectileImageName }
{}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseLongbow::use()
{
	if (!m_isAttacking)
	{
		onStart();
	}
}

void BaseLongbow::onStart()
{
	m_isAttacking = true;
	m_timeUntilNextAttack = LONGBOW_ATTACK_COOLDOWN_TIME;

	new Projectile(
		this, m_projectileImageName, 
		LONGBOW_PROJECTILE_COLLIDER_WIDTH, LONGBOW_PROJECTILE_COLLIDER_HEIGHT,  
		owner()->getTransform()->getX() + LONGBOW_PROJECTILE_SPAWN_X_OFFSET_FROM_HOLDER, 
		owner()->getTransform()->getY() + LONGBOW_PROJECTILE_SPAWN_Y_OFFSET_FROM_HOLDER, 
		LONGBOW_PROJECTILE_SPRITE_SCALE
	);
}

void BaseLongbow::onUpdate(int ticks)
{
	updateAttack(ticks);
}

void BaseLongbow::onEnd()
{
	m_isAttacking = false;
}

void BaseLongbow::updateAttack(int ticks)
{
	if (m_isAttacking)
	{
		m_timeUntilNextAttack -= ticks / TICKS_PER_SECOND;

		if (m_timeUntilNextAttack <= 0)
		{
			onEnd();
		}
	}
}
