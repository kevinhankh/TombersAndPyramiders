/*===================================================================================*//**
	DamagingRegion
	
	Prefab class for a GameObject that causes damage to damageable objects when it 
	collides with them.
    
    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include <stdexcept>
#include "DamagingRegion.h"
#include "BoxCollider.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
DamagingRegion::DamagingRegion(BaseWeapon* weapon, string imageName, float width, 
	float height, float xPosition, float yPosition, float scale) :
	SimpleSprite{ imageName, xPosition, yPosition, 0, scale },
	_weapon{ weapon }
{
	if (_weapon == nullptr)
	{
		throw std::invalid_argument("DamagingRegion::DamagingRegion(): _weapon cannot be null.");
	}

	if (width < 0)
	{
		throw std::invalid_argument("DamagingRegion::DamagingRegion(): colliderWidth must be non-negative.");
	}

	if (height < 0)
	{
		throw std::invalid_argument("DamagingRegion::DamagingRegion(): colliderHeight must be non-negative.");
	}



	// TODO: Add this line back in once Michael fixes BoxCollider.
	//addComponent<BoxCollider*>(new BoxCollider(this, colliderWidth, colliderHeight));
}

DamagingRegion::~DamagingRegion()
{}

/*----------------------------------------------------------------------------------------
	Instance Getter Methods
----------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------
	Instance Setter Methods
----------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void DamagingRegion::onUpdate(int ticks)
{

}
