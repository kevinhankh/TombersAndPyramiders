/*===================================================================================*//**
	Inventory
	
	A component representing a collection of items owned by a GameObject.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "Component.h"
#include "BaseWeapon.h"
#include "BaseShield.h"
#include "BaseHelmet.h"
#include "BaseChestplate.h"
#include "BaseGreaves.h"

/*========================================================================================
	Inventory	
========================================================================================*/
class Inventory : public Component
{
    /*----------------------------------------------------------------------------------------
		Instance Fields
    ----------------------------------------------------------------------------------------*/
    private:
		BaseWeapon* m_weapon;
		BaseShield* m_shield;
		BaseHelmet* m_helmet;
		BaseChestplate* m_chestplate;
		BaseGreaves* m_greaves;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        explicit Inventory() = delete;

		/**
			Initializes inventory with nullptr equipment.
		*/
		explicit Inventory(GameObject* gameobject);

		explicit Inventory(GameObject* gameobject, BaseWeapon* weapon, BaseShield* shield, BaseHelmet* helmet, 
			BaseChestplate* chestplate, BaseGreaves* greaves);

	/*----------------------------------------------------------------------------------------
		Instance Getter Methods
    ----------------------------------------------------------------------------------------*/
    public:
        
    
	/*----------------------------------------------------------------------------------------
		Instance Setter Methods
	----------------------------------------------------------------------------------------*/
    public:


	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
    public:
		void onStart();
		void onUpdate(int ticks);
		void onEnd();

    private:

};
