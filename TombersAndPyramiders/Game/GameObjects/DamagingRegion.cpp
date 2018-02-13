/*===================================================================================*//**
	DamagingRegion
	
	Prefab class for a GameObject that causes damage to damageable objects when it 
	collides with them.
    
    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include <stdexcept>
#include "DamagingRegion.h"
#include "BoxCollider.h"
#include "CharacterController.h"
#include "Damageable.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
DamagingRegion::DamagingRegion(string imageName, float colliderWidth, 
	float colliderHeight, float xPosition, float yPosition, float spriteScale) :
	SimpleSprite{ imageName, xPosition, yPosition, 0, spriteScale },
	m_damage{ 20 }, 
	m_destroyOnCollision{ false }
{
	if (colliderWidth < 0)
	{
		throw std::invalid_argument("DamagingRegion::DamagingRegion(): colliderWidth must be non-negative.");
	}

	if (colliderHeight < 0)
	{
		throw std::invalid_argument("DamagingRegion::DamagingRegion(): colliderHeight must be non-negative.");
	}

	/* TODO Weapon collider makes you crash into your own weapon. */
	m_collider = addComponent<BoxCollider>(this, colliderWidth, colliderHeight);
}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void DamagingRegion::setOwnerId(int id)
{
	m_ownerId = id;
}

void DamagingRegion::onUpdate(int ticks)
{
	handleCollisions();
}

void DamagingRegion::handleCollisions()
{
	if (m_collider != nullptr && m_collider->collisionDetected())
	{
		for (int i = 0; i < m_collider->getColliders().size(); i++)
		{
			handleSingleCollision(m_collider->getColliders()[i]);
		}
	}
}

void DamagingRegion::handleSingleCollision(GameObject* other)
{
	/* Ensure you don't collide with the thing that created you. */
	if (other->getId() != m_ownerId)
	{
		/* If the other thing is a character, damage it. */
		std::shared_ptr<CharacterController> ccOther = other->getComponent<CharacterController>();
		if (ccOther != nullptr)
		{
			ccOther->takeDamage(m_damage);

			if (m_destroyOnCollision)
			{
				destroy(getId());
			}

			return;
		}

		/* TODO Handle collision with walls? */
	}
}
