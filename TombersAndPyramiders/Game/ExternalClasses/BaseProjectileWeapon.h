/*===================================================================================*//**
	BaseProjectileWeapon
	
	Abstract class for a base projectile weapon.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseWeapon.h"
#include <string>

/*========================================================================================
	BaseProjectileWeapon	
========================================================================================*/
class BaseProjectileWeapon : public BaseWeapon
{
    /*----------------------------------------------------------------------------------------
		Instance Fields
    ----------------------------------------------------------------------------------------*/
	protected:
		std::string m_projectileImageName;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit BaseProjectileWeapon() = delete;

		explicit BaseProjectileWeapon(std::string projectileImageName);

		virtual ~BaseProjectileWeapon() {};
};
