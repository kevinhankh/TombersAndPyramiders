/*===================================================================================*//**
	BaseShortsword

	Abstract class for a base shortsword.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseShortsword.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const float BaseShortsword::SHORTSWORD_COLLIDER_WIDTH = 1;
const float BaseShortsword::SHORTSWORD_COLLIDER_HEIGHT = 1;
const float BaseShortsword::SHORTSWORD_X_OFFSET_FROM_HOLDER = 1;
const float BaseShortsword::SHORTSWORD_Y_OFFSET_FROM_HOLDER = 0;

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseShortsword::BaseShortsword() :
	BaseMeleeWeapon{ SHORTSWORD_COLLIDER_WIDTH, SHORTSWORD_COLLIDER_HEIGHT, 
	SHORTSWORD_X_OFFSET_FROM_HOLDER, SHORTSWORD_Y_OFFSET_FROM_HOLDER }
{}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseShortsword::use()
{

}

void BaseShortsword::onStart()
{}

void BaseShortsword::onUpdate(int ticks)
{
	BaseMeleeWeapon::updatePosition();
}

void BaseShortsword::onEnd()
{}
