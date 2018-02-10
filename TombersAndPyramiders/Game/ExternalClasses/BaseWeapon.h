/*===================================================================================*//**
	BaseWeapon
	
	Abstract class for a base weapon.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "Updateable.h"
#include "BaseEquippableItem.h"

/*========================================================================================
	BaseWeapon	
========================================================================================*/
class BaseWeapon : public BaseEquippableItem, public Updateable
{
    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit BaseWeapon() = default;

		virtual ~BaseWeapon() {};

	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
    public:
		/**
			Uses the weapon.
			This should be called every frame that the weapon is in use.

			Weapon classes that implement this will treat this either as a "trigger", 
			starting the use of the weapon and ignoring subsequent calls until the weapon 
			is ready for use again (e.g., swinging a sword), OR as a continuous "hold" for 
			weapons that can be used continuously (e.g., a flail that is swung around for 
			as long as the player holds the key).
		*/
		virtual void use() = 0;

		virtual void onStart() = 0;
		virtual void onUpdate(int ticks) = 0;
		virtual void onEnd() = 0;

	protected:
		void addSubclassToInventory();
};
