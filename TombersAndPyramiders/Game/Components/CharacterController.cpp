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

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
CharacterController::CharacterController(GameObject* gameObject, BasePilot* pilot, int maxHealth) :
	BaseController(gameObject, pilot), Damageable(maxHealth)
{}
