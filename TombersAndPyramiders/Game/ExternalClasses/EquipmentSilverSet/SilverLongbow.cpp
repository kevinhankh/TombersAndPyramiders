/*===================================================================================*//**
	BaseLongbow

	Abstract class for a base longbow.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "SilverLongbow.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const int SilverLongbow::SILVER_LONGBOW_DAMAGE = 35;
const std::string SilverLongbow::SILVER_LONGBOW_PROJECTILE_IMAGE_NAME = "TempSilverArrow.png";
const bool SilverLongbow::SILVER_LONGBOW_DESTROY_PROJECTILES_ON_COLLISION = true;

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
SilverLongbow::SilverLongbow() :
	BaseLongbow{ SILVER_LONGBOW_DAMAGE, SILVER_LONGBOW_PROJECTILE_IMAGE_NAME,
		Vector2(LONGBOW_PROJECTILE_COLLIDER_WIDTH, LONGBOW_PROJECTILE_COLLIDER_HEIGHT), 
		SILVER_LONGBOW_DESTROY_PROJECTILES_ON_COLLISION,
		Vector2(LONGBOW_PROJECTILE_SPAWN_X_OFFSET_FROM_HOLDER, LONGBOW_PROJECTILE_SPAWN_Y_OFFSET_FROM_HOLDER), 
		LONGBOW_PROJECTILE_SPRITE_SCALE, 
		Vector2(LONGBOW_PROJECTILE_X_VELOCITY, LONGBOW_PROJECTILE_Y_VELOCITY), 
		LONGBOW_PROJECTILE_LIFESPAN }
{
	m_itemIcon = "SilverLongbow.png"; 
}
