/*===================================================================================*//**
	WoodenShortsword

	Abstract class for a base shortsword.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "WoodenShortsword.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const int WoodenShortsword::WOODEN_SHORTSWORD_DAMAGE = 20;
const string WoodenShortsword::WOODEN_SHORTSWORD_IMAGE_NAME = "IceTile.png";

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
WoodenShortsword::WoodenShortsword() :
	BaseShortsword{ WOODEN_SHORTSWORD_DAMAGE, WOODEN_SHORTSWORD_IMAGE_NAME }
{
	m_itemIcon = "WoodenShortsword.png";
}
