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
#include "Inventory.h"
#include "GameManager.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseMeleeWeapon::BaseMeleeWeapon(int damage, string imageName, float colliderWidth, float colliderHeight, 
	bool destroyOnCollision, 
	float xOffsetFromHolder, float yOffsetFromHolder, float colliderScale) :
	BaseWeapon(damage)
{
	m_offsetFromHolder = Vector2(xOffsetFromHolder, yOffsetFromHolder);
	m_damagingRegion = GameManager::getInstance()->createGameObject<DamagingRegion>(false, damage, imageName, 
		colliderWidth, colliderHeight, destroyOnCollision, 0, 0, colliderScale);
}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseMeleeWeapon::setOwnerId(int id)
{
	m_damagingRegion->setOwnerId(id);
}

void BaseMeleeWeapon::updatePosition()
{
	if (owner() != nullptr)
	{
		/* Get the coordinates of the weapon before rotation. */
		float newX = owner()->getTransform()->getX() + m_offsetFromHolder.getX();
		float newY = owner()->getTransform()->getY() + m_offsetFromHolder.getY();
		
		/* Rotate the position about the weapon holder. */
		Vector2 newPosition = Vector2(newX, newY);
		newPosition.rotateFromOrigin(
			Vector2(owner()->getTransform()->getX(), owner()->getTransform()->getY()),
			owner()->getTransform()->getRotation()
		);

		m_damagingRegion->getTransform()->setPosition(newPosition.getX(), newPosition.getY());

		/* Set the weapon's rotation about its center. */
		m_damagingRegion->getTransform()->setRotation(owner()->getTransform()->getRotation());
	}
}
