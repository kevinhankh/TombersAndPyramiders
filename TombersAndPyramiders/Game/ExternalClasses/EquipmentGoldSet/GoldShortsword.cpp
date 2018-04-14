/*===================================================================================*//**
	GoldShortsword

	Abstract class for a base shortsword.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "GoldShortsword.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const int GoldShortsword::GOLD_SHORTSWORD_DAMAGE = 50;
const string GoldShortsword::GOLD_SHORTSWORD_IMAGE_NAME = "TempGoldShortsword.png";
const bool GoldShortsword::GOLD_SHORTSWORD_DESTROY_ON_COLLISION = false;

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
GoldShortsword::GoldShortsword() :
	BaseShortsword{ GOLD_SHORTSWORD_DAMAGE, GOLD_SHORTSWORD_IMAGE_NAME, GOLD_SHORTSWORD_DESTROY_ON_COLLISION }
{
	m_itemIcon = "GoldShortsword.png";
}
