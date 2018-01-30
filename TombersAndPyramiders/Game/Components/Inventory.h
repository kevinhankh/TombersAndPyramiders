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

class BaseItem;
class BaseWeapon;
class BaseShield;
class BaseHelmet;
class BaseChestplate;
class BaseGreaves;

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
		/**
			Adds an item to the inventory.
			addItem() will resolve the item's type and add it appropriately.
		*/
		void addItem(BaseItem* item);
		void addWeapon(BaseWeapon* weapon);
		void addShield(BaseShield* shield);
		void addHelmet(BaseHelmet* helmet);
		void addChestplate(BaseChestplate* chestplate);
		void addGreaves(BaseGreaves* greaves);

		void onStart();
		void onUpdate(int ticks);
		void onEnd();

    private:

};
