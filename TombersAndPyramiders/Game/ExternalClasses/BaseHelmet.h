/*===================================================================================*//**
	BaseHelmet
	
	Abstract class for a base helmet.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseEquippableItem.h"

/*========================================================================================
	BaseHelmet	
========================================================================================*/
class BaseHelmet : public BaseEquippableItem, public std::enable_shared_from_this<BaseHelmet>
{
    /*----------------------------------------------------------------------------------------
		Static Fields
    ----------------------------------------------------------------------------------------*/
	public:
		static const float WOODEN_HELMET_CRITICAL_RESIST_CHANCE;
		static const float SILVER_HELMET_CRITICAL_RESIST_CHANCE;
		static const float GOLD_HELMET_CRITICAL_RESIST_CHANCE;

    /*----------------------------------------------------------------------------------------
		Instance Fields
    ----------------------------------------------------------------------------------------*/
    private:
		float m_criticalResistChance;	/* Chance of ignoring the extra damage from a critical hit. */

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit BaseHelmet() = delete;

		explicit BaseHelmet(float criticalResistChance);

		virtual ~BaseHelmet() {};

	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
    public:
		virtual bool doesAvoidCriticalHit();
		virtual void setProperties(float criticalResistChance);

	protected:
		std::shared_ptr<BaseItem> addSubclassToInventory();
};
