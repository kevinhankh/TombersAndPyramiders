/*===================================================================================*//**
	BaseLongbow

	Abstract class for a base longbow.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "GoldLongbow.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const int GoldLongbow::GOLD_LONGBOW_DAMAGE = 50;
const std::string GoldLongbow::GOLD_LONGBOW_PROJECTILE_IMAGE_NAME = "TempGoldArrow.png";
const bool GoldLongbow::GOLD_LONGBOW_DESTROY_PROJECTILES_ON_COLLISION = false;

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
GoldLongbow::GoldLongbow() :
	BaseLongbow{ GOLD_LONGBOW_DAMAGE, GOLD_LONGBOW_PROJECTILE_IMAGE_NAME,
		Vector2(LONGBOW_PROJECTILE_COLLIDER_WIDTH, LONGBOW_PROJECTILE_COLLIDER_HEIGHT), 
		GOLD_LONGBOW_DESTROY_PROJECTILES_ON_COLLISION,
		Vector2(LONGBOW_PROJECTILE_SPAWN_X_OFFSET_FROM_HOLDER, LONGBOW_PROJECTILE_SPAWN_Y_OFFSET_FROM_HOLDER), 
		LONGBOW_PROJECTILE_SPRITE_SCALE, 
		Vector2(LONGBOW_PROJECTILE_X_VELOCITY, LONGBOW_PROJECTILE_Y_VELOCITY), 
		LONGBOW_PROJECTILE_LIFESPAN }
{
	m_itemIcon = "GoldLongbow.png"; 
}
