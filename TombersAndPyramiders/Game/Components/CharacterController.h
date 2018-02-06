/*===================================================================================*//**
	CharacterController
	
	A controller that controls a player character.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseController.h"
#include "Damageable.h"
class Vector2;

/*========================================================================================
	CharacterController	
========================================================================================*/
class CharacterController : public BaseController, public Damageable
{
    /*----------------------------------------------------------------------------------------
		Instance Fields
    ----------------------------------------------------------------------------------------*/
	private:

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        explicit CharacterController() = delete;

		explicit CharacterController(GameObject* gameObject, BasePilot* pilot, int maxHealth);

    /*----------------------------------------------------------------------------------------
		Instance Methods
    ----------------------------------------------------------------------------------------*/
	public:
		/**
			Moves this component's gameObject.
		*/
		void move(Vector2 delta);

		/**
			Uses the player's weapon this tick.

			This will either start or continue the use of the weapon, 
			depending on whether the weapon was in use in the last tick.
		*/
		void useWeapon();

		/**
			Uses the player's shield this tick.

			This will either start or continue the use of the shield, 
			depending on whether the shield was in use in the last tick.
		*/
		void useShield();

		/**
			Uses the player's greaves this tick.

			This will either start or continue the use of the greaves, 
			depending on whether the greaves were in use in the last tick.
		*/
		void useGreaves();

	protected:
		/**
			Called when the character's HP reaches zero.
			Handles the player's death.
		*/
		void death();
};
