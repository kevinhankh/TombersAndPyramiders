/*===================================================================================*//**
	BaseChestplate
	
	Abstract class for a base chestplate

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseChestplate.h"
#include "Inventory.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const std::string BaseChestplate::WOODEN_CHESTPLATE_ICON_IMAGE_NAME = "WoodenChestplateIcon.png";
const float BaseChestplate::WOODEN_CHESTPLATE_DAMAGE_MULTIPLIER = 0.95;
const std::string BaseChestplate::SILVER_CHESTPLATE_ICON_IMAGE_NAME = "SilverChestplateIcon.png";
const float BaseChestplate::SILVER_CHESTPLATE_DAMAGE_MULTIPLIER = 0.85;
const std::string BaseChestplate::GOLD_CHESTPLATE_ICON_IMAGE_NAME = "GoldChestplateIcon.png";
const float BaseChestplate::GOLD_CHESTPLATE_DAMAGE_MULTIPLIER = 0.75;

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseChestplate::BaseChestplate(std::string iconImageName, float damageMultiplier) :
	m_damageMultiplier{ damageMultiplier }
{
	m_itemIcon = iconImageName;
	setupSprites();
	m_zIndex = 101;
}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
int BaseChestplate::calculateRealDamage(int damage)
{
	return (int)((float)damage * m_damageMultiplier);
}

void BaseChestplate::setProperties(std::string iconImageName, float damageMultiplier)
{
	m_itemIcon = iconImageName;
	m_damageMultiplier = damageMultiplier;
}

std::shared_ptr<BaseItem> BaseChestplate::addSubclassToInventory()
{
	return m_inventory->setChestplate(shared_from_this());
}


/*----------------------------------------------------------------------------------------
| Setup Sprites and Animations
----------------------------------------------------------------------------------------*/
void BaseChestplate::setupSprites()
{
	spriteInfo = std::make_shared<ComplexSpriteInfo>();

	addSprite("Player/Walk/chestplate.png", "walk", 9, 4);
	addAnimation("walk", "WalkUp", 1, 8);
	addAnimation("walk", "WalkLeft", 10, 17);
	addAnimation("walk", "WalkDown", 19, 26);
	addAnimation("walk", "WalkRight", 28, 35);
	addAnimation("walk", "IdleUp", 0, 0);
	addAnimation("walk", "IdleLeft", 9, 9);
	addAnimation("walk", "IdleDown", 18, 18);
	addAnimation("walk", "IdleRight", 27, 27);

	addSprite("Player/Attack/Bow/chestplate.png", "shoot", 13, 4);
	addAnimation("shoot", "ShootUp", 1, 12);
	addAnimation("shoot", "ShootLeft", 14, 25);
	addAnimation("shoot", "ShootDown", 27, 38);
	addAnimation("shoot", "ShootRight", 40, 51);
	addAnimation("shoot", "IdleUp", 0, 0);
	addAnimation("shoot", "IdleLeft", 13, 13);
	addAnimation("shoot", "IdleDown", 26, 26);
	addAnimation("shoot", "IdleRight", 39, 39);

	addSprite("Player/Attack/Melee/chestplate.png", "slash", 6, 4);
	addAnimation("slash", "SlashUp", 1, 5);
	addAnimation("slash", "SlashLeft", 7, 11);
	addAnimation("slash", "SlashDown", 13, 17);
	addAnimation("slash", "SlashRight", 19, 23);
	addAnimation("slash", "IdleUp", 0, 0);
	addAnimation("slash", "IdleLeft", 6, 6);
	addAnimation("slash", "IdleDown", 12, 12);
	addAnimation("slash", "IdleRight", 18, 18);
}