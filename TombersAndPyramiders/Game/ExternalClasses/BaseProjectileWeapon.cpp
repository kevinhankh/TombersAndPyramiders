/*===================================================================================*//**
	BaseProjectileWeapon

	Abstract class for a base projectile weapon.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseProjectileWeapon.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseProjectileWeapon::BaseProjectileWeapon(std::string projectileImageName) :
	m_projectileImageName{ projectileImageName }
{}
