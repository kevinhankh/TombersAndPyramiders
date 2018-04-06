/*===================================================================================*//**
	SilverShield
	
	A weak silver shield.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "SilverShield.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const string SilverShield::SILVER_SHIELD_IMAGE_NAME = "TempSilverShield.png";
const float SilverShield::SILVER_SHIELD_DAMAGE_MULT = 0.9f;
const float SilverShield::SILVER_SHIELD_COOLDOWN_TIME = 0.5f;

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
SilverShield::SilverShield() :
	BaseShield(SILVER_SHIELD_IMAGE_NAME, SILVER_SHIELD_DAMAGE_MULT, SILVER_SHIELD_COOLDOWN_TIME)
{}
