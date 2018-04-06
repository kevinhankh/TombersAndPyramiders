/*===================================================================================*//**
	SilverShortsword

	Abstract class for a base shortsword.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "SilverShortsword.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const int SilverShortsword::SILVER_SHORTSWORD_DAMAGE = 20;
const string SilverShortsword::SILVER_SHORTSWORD_IMAGE_NAME = "TempSilverShortsword.png";
const bool SilverShortsword::SILVER_SHORTSWORD_DESTROY_ON_COLLISION = false;

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
SilverShortsword::SilverShortsword() :
	BaseShortsword{ SILVER_SHORTSWORD_DAMAGE, SILVER_SHORTSWORD_IMAGE_NAME, SILVER_SHORTSWORD_DESTROY_ON_COLLISION }
{
	m_itemIcon = "SilverShortsword.png";
}
