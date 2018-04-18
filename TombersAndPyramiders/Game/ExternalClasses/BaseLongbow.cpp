/*===================================================================================*//**
	BaseLongbow
	Abstract class for a base longbow.
    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseLongbow.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const float BaseLongbow::LONGBOW_PROJECTILE_COLLIDER_WIDTH = 0.5;
const float BaseLongbow::LONGBOW_PROJECTILE_COLLIDER_HEIGHT = 0.5;
const float BaseLongbow::LONGBOW_PROJECTILE_SPRITE_SCALE = 1.0;
const float BaseLongbow::LONGBOW_PROJECTILE_SPAWN_X_OFFSET_FROM_HOLDER = 1;
const float BaseLongbow::LONGBOW_PROJECTILE_SPAWN_Y_OFFSET_FROM_HOLDER = 0;
const float BaseLongbow::LONGBOW_PROJECTILE_LIFESPAN = 3;
const float BaseLongbow::LONGBOW_PROJECTILE_X_VELOCITY = 40;
const float BaseLongbow::LONGBOW_PROJECTILE_Y_VELOCITY = 0;
const float BaseLongbow::LONGBOW_CRITICAL_HIT_CHANCE = 0.05f;
const float BaseLongbow::LONGBOW_ATTACK_COOLDOWN_TIME = 0.5f;

const int BaseLongbow::WOODEN_LONGBOW_DAMAGE = 20;
const std::string BaseLongbow::WOODEN_LONGBOW_IMAGE_NAME = "WoodenLongbow.png";
const std::string BaseLongbow::WOODEN_LONGBOW_PROJECTILE_IMAGE_NAME = "TempWoodenArrow.png";
const bool BaseLongbow::WOODEN_LONGBOW_DESTROY_PROJECTILES_ON_COLLISION = true;

const int BaseLongbow::SILVER_LONGBOW_DAMAGE = 35;
const std::string BaseLongbow::SILVER_LONGBOW_IMAGE_NAME = "SilverLongbow.png";
const std::string BaseLongbow::SILVER_LONGBOW_PROJECTILE_IMAGE_NAME = "TempSilverArrow.png";
const bool BaseLongbow::SILVER_LONGBOW_DESTROY_PROJECTILES_ON_COLLISION = true;

const int BaseLongbow::GOLD_LONGBOW_DAMAGE = 50;
const std::string BaseLongbow::GOLD_LONGBOW_IMAGE_NAME = "GoldLongbow.png";
const std::string BaseLongbow::GOLD_LONGBOW_PROJECTILE_IMAGE_NAME = "TempGoldArrow.png";
const bool BaseLongbow::GOLD_LONGBOW_DESTROY_PROJECTILES_ON_COLLISION = false;

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseLongbow::BaseLongbow(int damage, std::string bowImageName, std::string projectileImageName, bool destroyProjectilesOnCollision) :
	BaseProjectileWeapon{ damage, projectileImageName, 
	Vector2(LONGBOW_PROJECTILE_COLLIDER_WIDTH, LONGBOW_PROJECTILE_COLLIDER_HEIGHT), 
	destroyProjectilesOnCollision, LONGBOW_CRITICAL_HIT_CHANCE, LONGBOW_ATTACK_COOLDOWN_TIME, 
	Vector2(LONGBOW_PROJECTILE_SPAWN_X_OFFSET_FROM_HOLDER, LONGBOW_PROJECTILE_SPAWN_Y_OFFSET_FROM_HOLDER), 
	LONGBOW_PROJECTILE_SPRITE_SCALE, Vector2(LONGBOW_PROJECTILE_X_VELOCITY, LONGBOW_PROJECTILE_Y_VELOCITY), 
	LONGBOW_PROJECTILE_LIFESPAN }
{
	m_itemIcon = bowImageName;

	if (projectileImageName == "beetle_spit.png")
	{
		m_zIndex = -100;
	}
	else
	{
		m_zIndex = 102;
		setupSprites();
	}
}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseLongbow::setProperties(int damage, std::string bowImageName, std::string projectileImageName, bool destroyProjectilesOnCollision)
{
	m_damage = damage;
	m_itemIcon = bowImageName;
	m_projectileImageName = projectileImageName;
	m_destroyProjectilesOnCollision = destroyProjectilesOnCollision;
}

/*----------------------------------------------------------------------------------------
| Setup Sprites and Animations
----------------------------------------------------------------------------------------*/
void BaseLongbow::setupSprites()
{
	spriteInfo = std::make_shared<ComplexSpriteInfo>();

	addSprite("Player/Walk/bow.png", "walk", 9, 4);
	addAnimation("walk", "WalkUp", 1, 8);
	addAnimation("walk", "WalkLeft", 10, 17);
	addAnimation("walk", "WalkDown", 19, 26);
	addAnimation("walk", "WalkRight", 28, 35);
	addAnimation("walk", "IdleUp", 0, 0);
	addAnimation("walk", "IdleLeft", 9, 9);
	addAnimation("walk", "IdleDown", 18, 18);
	addAnimation("walk", "IdleRight", 27, 27);

	addSprite("Player/Attack/Bow/bow.png", "shoot", 13, 4);
	addAnimation("shoot", "ShootUp", 1, 12);
	addAnimation("shoot", "ShootLeft", 14, 25);
	addAnimation("shoot", "ShootDown", 27, 38);
	addAnimation("shoot", "ShootRight", 40, 51);
	addAnimation("shoot", "IdleUp", 0, 0);
	addAnimation("shoot", "IdleLeft", 13, 13);
	addAnimation("shoot", "IdleDown", 26, 26);
	addAnimation("shoot", "IdleRight", 39, 39);
}