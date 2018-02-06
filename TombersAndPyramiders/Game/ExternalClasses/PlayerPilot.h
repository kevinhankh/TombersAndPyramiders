/*===================================================================================*//**
	PlayerPilot
	
	A pilot that gets local keyboard input from the player.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BasePilot.h"
class CharacterController;

/*========================================================================================
	PlayerPilot	
========================================================================================*/
class PlayerPilot : public BasePilot
{
    /*----------------------------------------------------------------------------------------
		Instance Fields
    ----------------------------------------------------------------------------------------*/
	CharacterController* m_characterController; /* Note this is delibrately a raw pointer.
													Pilots do not own their controllers and should not delete them. */

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit PlayerPilot() = default;

	
	/*----------------------------------------------------------------------------------------
		Instance Setter Methods
	----------------------------------------------------------------------------------------*/
	public:
		/**
			This method assumes that the controller being passed is a CharacterController.
		*/
		void setController(BaseController* controller);

	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
    public:
		void onStart();

		/**
			Reads player input and drives the pilot's controller accordingly.
		*/
		void onUpdate(int ticks);
		
		void onEnd();
};
