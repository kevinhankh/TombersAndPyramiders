/*===================================================================================*//**
	BaseController
	
	Abstract class for a component that controls the actions of an agent.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseController.h"
#include "BasePilot.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseController::BaseController(GameObject* gameObject) :
	Component(gameObject)
{}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseController::onStart()
{
	m_pilot.get()->onStart();
}

void BaseController::onUpdate(int ticks)
{
	m_pilot.get()->onUpdate(ticks);
}

void BaseController::onEnd()
{
	m_pilot.get()->onEnd();
}
