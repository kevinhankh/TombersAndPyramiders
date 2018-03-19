/*===================================================================================*//**
	WoodenShield
	
	A weak wooden shield.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseShield.h"

/*========================================================================================
	BaseShield	
========================================================================================*/
class WoodenShield : public BaseShield
{
    /*----------------------------------------------------------------------------------------
		Static Fields
    ----------------------------------------------------------------------------------------*/
	private:
		static const string WOODEN_SHIELD_IMAGE_NAME;
		static const float WOODEN_SHIELD_DAMAGE_MULT;
		static const float WOODEN_SHIELD_COOLDOWN_TIME;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
		explicit WoodenShield();

		~WoodenShield() = default;

	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
    
};