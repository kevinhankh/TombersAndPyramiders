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
	m_ownerId{ 0 }, 
	m_damage{ 0 }, 
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

	// TODO: Add this line back in once Michael fixes BoxCollider.
	//addComponent<BoxCollider*>(new BoxCollider(this, colliderWidth, colliderHeight));

	m_collider = getComponent<Collider>();
}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void DamagingRegion::onUpdate(int ticks)
{
	handleCollisions();
}

void DamagingRegion::handleCollisions()
{
	if (m_collider != nullptr)
	{
		for (auto& eachCollisionObject : m_collider->getColliders())
		{
			handleSingleCollision(eachCollisionObject);
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
