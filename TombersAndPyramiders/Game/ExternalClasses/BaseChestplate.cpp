/*===================================================================================*//**
	BaseChestplate
	
	Abstract class for a base chestplate

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseChestplate.h"
#include <stdexcept>

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseChestplate::BaseChestplate(int durability, float absorptionPercent) :
	m_durability{ durability }, m_absorptionPercent{ absorptionPercent }
{
	if (durability < 0)
	{
		throw std::invalid_argument("BaseChestplate::BaseChestplate: durability must be 0 or greater.");
	}

	if (absorptionPercent < 0 ||
		absorptionPercent > 1)
	{
		throw std::invalid_argument("BaseChestplate::BaseChestplate: absorptionPercent must be in the range [0-1].");
	}
}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
int BaseChestplate::absorbDamage(int damage)
{
	if (damage < 0)
	{
		throw std::invalid_argument("BaseChestplate::AbsorbDamage: damage must be 0 or greater.");
	}

	/* No absorption if the chestplate is already broken. */
	if (m_durability <= 0)
	{
		return damage;
	}

	int absorbed = damage * m_absorptionPercent;
	m_durability -= absorbed;

	if (m_durability <= 0)
	{
		destroy();
	}

	return (damage - absorbed);
}

void BaseChestplate::destroy()
{
	/* Nothing to do for now. */
}
