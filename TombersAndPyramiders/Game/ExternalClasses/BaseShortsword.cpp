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

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseShortsword::BaseShortsword() :
	BaseMeleeWeapon{ SHORTSWORD_COLLIDER_WIDTH, SHORTSWORD_COLLIDER_HEIGHT }
{}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseShortsword::onStart()
{}

void BaseShortsword::onUpdate(int ticks)
{}

void BaseShortsword::onEnd()
{}
