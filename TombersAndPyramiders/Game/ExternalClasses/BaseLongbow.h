/*===================================================================================*//**
	BaseLongbow
	
	Abstract class for a base longbow.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseProjectileWeapon.h"
#include <string>

/*========================================================================================
	BaseLongbow	
========================================================================================*/
class BaseLongbow : public BaseProjectileWeapon
{
    /*----------------------------------------------------------------------------------------
		Static Fields
    ----------------------------------------------------------------------------------------*/
	protected:
		static const float LONGBOW_PROJECTILE_COLLIDER_WIDTH;
		static const float LONGBOW_PROJECTILE_COLLIDER_HEIGHT;
		static const float LONGBOW_PROJECTILE_SPRITE_SCALE;
		static const float LONGBOW_PROJECTILE_SPAWN_X_OFFSET_FROM_HOLDER;
		static const float LONGBOW_PROJECTILE_SPAWN_Y_OFFSET_FROM_HOLDER;
		static const float LONGBOW_PROJECTILE_LIFESPAN;
		static const float LONGBOW_PROJECTILE_X_VELOCITY;
		static const float LONGBOW_PROJECTILE_Y_VELOCITY;
		static const float LONGBOW_ATTACK_COOLDOWN_TIME;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit BaseLongbow() = delete;

		explicit BaseLongbow(std::string projectileImageName);

		virtual ~BaseLongbow() {};
		
    /*----------------------------------------------------------------------------------------
		Instance Methods
    ----------------------------------------------------------------------------------------*/
	public:
		void use();

		void onStart();
		void onUpdate(int ticks);
		void onEnd();

	protected:
		void updateAttack(int ticks);
};
