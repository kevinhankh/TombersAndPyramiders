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
const float BaseLongbow::LONGBOW_ATTACK_COOLDOWN_TIME = 5;

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
		this, "IceTile.png", 0.5, 0.5, 
		owner()->getTransform()->getX(), 
		owner()->getTransform()->getY(), 
		0.5
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
