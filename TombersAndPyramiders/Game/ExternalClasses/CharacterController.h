/*===================================================================================*//**
	CharacterController
	
	Abstract class for a component that controls the behaviour of a player character.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "Component.h"
class GameObject;

/*========================================================================================
	BaseController	
========================================================================================*/
class BaseController : Component
{
    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        explicit BaseController() = delete;

		explicit BaseController(GameObject* gameObject);

		virtual ~BaseController() {};

	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
	public:
		virtual void onStart();
		virtual void onUpdate(int ticks);
		virtual void onEnd();
};
