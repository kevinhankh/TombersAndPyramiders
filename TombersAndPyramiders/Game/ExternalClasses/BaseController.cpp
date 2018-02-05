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
{}

void BaseController::onUpdate(int ticks)
{}

void BaseController::onEnd()
{}
