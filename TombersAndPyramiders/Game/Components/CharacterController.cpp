/*===================================================================================*//**
	CharacterController
	
	Abstract class for a component that controls the actions of an agent.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "CharacterController.h"
#include "BaseController.h"
#include "BasePilot.h"
#include "Vector2.h"
#include "Component.h"
#include "GameObject.h"
#include "Inventory.h"
#include "BaseWeapon.h"
#include "BaseShield.h"
#include "BaseGreaves.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const int CharacterController::DEFAULT_PLAYER_MAX_HP = 100;
const Vector2 CharacterController::DEFAULT_PLAYER_MOVEMENT_SPEED = Vector2(1, 1);

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
CharacterController::CharacterController(GameObject* gameObject, Inventory* inventory, 
	BasePilot* pilot, int maxHealth, Vector2 movementSpeed) :
	BaseController(gameObject, pilot), Damageable(maxHealth), 
	m_inventory{ inventory },
	m_movementSpeed{ movementSpeed }, 
	m_wasUsingWeapon{ false }, m_wasUsingShield{ false }, m_wasUsingGreaves{ false },
	m_isUsingWeapon{ false }, m_isUsingShield{ false }, m_isUsingGreaves{ false }
{
	if (m_inventory == nullptr)
	{
		throw std::invalid_argument("CharacterController::CharacterController(): m_inventory cannot be null.");
	}
}


/*----------------------------------------------------------------------------------------
	Instance Setter Methods
----------------------------------------------------------------------------------------*/
void CharacterController::setIsUsingWeapon(bool isUsingWeapon)
{
	m_wasUsingWeapon = m_isUsingWeapon;
	m_isUsingWeapon = isUsingWeapon;

}

void CharacterController::setIsUsingShield(bool isUsingShield)
{
	m_wasUsingShield = m_isUsingShield;
	m_isUsingShield = isUsingShield;
}

void CharacterController::setIsUsingGreaves(bool isUsingGreaves)
{
	m_wasUsingGreaves = m_isUsingGreaves;
	m_isUsingGreaves = isUsingGreaves;
}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void CharacterController::onUpdate(int ticks)
{
	m_pilot.get()->onUpdate(ticks);

	updateWeapon(ticks);
	updateShield(ticks);
	updateGreaves(ticks);
}

void CharacterController::move(Vector2 delta)
{
	delta.setX(delta.getX() * m_movementSpeed.getX());
	delta.setY(delta.getY() * m_movementSpeed.getY());

	gameObject->getComponent<Transform*>()->addTranslation(delta.getX(), delta.getY());
}

void CharacterController::updateWeapon(int ticks)
{
	if (m_inventory->getWeapon() != nullptr)
	{
		m_inventory->getWeapon()->onUpdate(ticks);
	}
}

void CharacterController::updateShield(int ticks)
{

}

void CharacterController::updateGreaves(int ticks)
{

}

void CharacterController::death()
{

}
