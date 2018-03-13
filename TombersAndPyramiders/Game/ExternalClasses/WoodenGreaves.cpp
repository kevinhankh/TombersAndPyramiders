/*===================================================================================*//**
	WoodenGreaves
	
	A pair of weak wooden greaves.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "WoodenGreaves.h"
#include "GameObject.h"
#include "Vector2.h"
#include "CharacterController.h"

/*----------------------------------------------------------------------------------------
Static Fields
----------------------------------------------------------------------------------------*/
const float WoodenGreaves::WOODEN_GREAVES_COOLDOWN_TIME = 0.5f;
const float WoodenGreaves::WOODEN_GREAVES_DASH_DURATION = 3.0f;
const float WoodenGreaves::WOODEN_GREAVES_MAX_DASH_SPEED = 100.0f;

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
WoodenGreaves::WoodenGreaves() :
	BaseGreaves(WOODEN_GREAVES_COOLDOWN_TIME), 
	m_timeLeftInDash{ 0.0f }, 
	m_dashDirection{ std::make_unique<Vector2>() }
{}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void WoodenGreaves::onStart()
{
	BaseGreaves::onStart();
	m_timeLeftInDash = WOODEN_GREAVES_DASH_DURATION;
}

void WoodenGreaves::effect(int ticks)
{
	auto dashRotation = owner()->getTransform()->getRotation();
	auto dashAmount = ((float)ticks / 1000) * WOODEN_GREAVES_MAX_DASH_SPEED;
	auto dashDirection = Vector2(1, 0);
	dashDirection.rotate(dashRotation);
	Vector2* pDashDuration = dashDirection * dashAmount;

	//owner()->getTransform()->addTranslation(pDashDuration->getX(), pDashDuration->getY());
	//owner()->getComponent<Rigidbody>()->setVelocity(*pDashDuration);
	owner()->getComponent<CharacterController>()->move(*pDashDuration);
}
