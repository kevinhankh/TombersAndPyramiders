/*===================================================================================*//**
	BaseShield
	
	Abstract class for a base shield.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseShield.h"
#include "Inventory.h"
#include "GameManager.h"

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
BaseShield::BaseShield() :
	m_isBlocking{ false }, 
	m_defense{ 5 }, 
	m_blockCooldownTime{ 0.5f }, 
	m_offsetFromHolder{ Vector2(1, 0) }
{
	m_sprite = GameManager::getInstance()->createGameObject<SimpleSprite>(false, "IceTile.png", 0, 0, 0, 1.0f);
	m_sprite->getTransform()->setScale(0);
}

std::shared_ptr<BaseItem> BaseShield::addSubclassToInventory()
{
	return m_inventory->setShield(shared_from_this());
}

bool BaseShield::use()
{
	auto willBlock = !m_isBlocking;

	if (willBlock)
	{
		onStart();
	}

	return willBlock;
}

void BaseShield::onStart()
{
	m_isBlocking = true;
	m_timeUntilNextBlock = m_blockCooldownTime;
	m_sprite->getTransform()->setScale(1);
}

void BaseShield::onUpdate(int ticks)
{
	updatePosition();
	updateBlock(ticks);
}

void BaseShield::onEnd()
{
	m_isBlocking = false;
	m_sprite->getTransform()->setScale(0);
}

void BaseShield::updatePosition()
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

		m_sprite->getTransform()->setPosition(newPosition.getX(), newPosition.getY());

		/* Set the weapon's rotation about its center. */
		m_sprite->getTransform()->setRotation(owner()->getTransform()->getRotation());
	}
}

void BaseShield::updateBlock(int ticks)
{
	if (m_isBlocking)
	{
		m_timeUntilNextBlock -= (float)ticks / 1000.0f;

		if (m_timeUntilNextBlock <= 0)
		{
			onEnd();
		}
	}
}

bool BaseShield::isBlocking()
{
	return m_isBlocking;
}
