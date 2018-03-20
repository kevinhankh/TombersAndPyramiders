/*===================================================================================*//**
	Character
	
	Prefab class for any character.
    
    Copyright 2017 Erick Fernandez de Arteaga. All rights reserved.
        https://www.linkedin.com/in/erick-fda
        https://bitbucket.org/erick-fda
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "Character.h"
#include "CharacterController.h"
#include "Inventory.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
Character::Character(BasePilot* basePilot) :
	ComplexSprite(generateComplexSpriteInfo(), 0, 0)
{
	setFPS(12);
	Inventory* inventory = addComponent<Inventory>(this).get();
	addComponent<CharacterController>(this, inventory, basePilot);
}

/*----------------------------------------------------------------------------------------
	Instance Getter Methods
----------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------
	Instance Setter Methods
----------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void Character::onUpdate(int ticks)
{
	updateFrames(ticks);
}

// Private generation logic for describing the sprite sheet relationships for this player
std::shared_ptr<ComplexSpriteinfo> Character::generateComplexSpriteInfo()
{
	std::shared_ptr<ComplexSpriteinfo> spriteInfo = std::make_shared<ComplexSpriteinfo>();

	spriteInfo->addInfo("tanm_walk_up.png", 9, 1);
	spriteInfo->addInfo("tanm_walk_right.png", 9, 1);
	spriteInfo->addInfo("tanm_walk_down.png", 9, 1);
	spriteInfo->addInfo("tanm_walk_left.png", 9, 1);
	spriteInfo->addInfo("tanm_idle_up.png", 1, 1);
	spriteInfo->addInfo("tanm_idle_right.png", 1, 1);
	spriteInfo->addInfo("tanm_idle_down.png", 1, 1);
	spriteInfo->addInfo("tanm_idle_left.png", 1, 1);
	spriteInfo->addInfo("squareRedAttack.png", 8, 1);
	spriteInfo->addInfo("squareWhiteAttack.png", 8, 1);
	spriteInfo->addInfo("squareHurt.png", 8, 1);
	
	return spriteInfo;
}

// Changes the sprite animation to running
void Character::playRunAnimation(float rotation)
{
	if (rotation < 90)
	{
		changeSprite(ANIMATION_WALK_RIGHT);
	}
	else if (rotation < 180)
	{
		changeSprite(ANIMATION_WALK_DOWN);
	}
	else if (rotation < 270)
	{
		changeSprite(ANIMATION_WALK_LEFT);
	}
	else
	{
		changeSprite(ANIMATION_WALK_UP);
	}
}


// Changes the sprite animation to idling
void Character::endRunAnimation(float rotation)
{
	switch (getCurrentSprite())
	{
	case ANIMATION_WALK_UP:
		changeSprite(ANIMATION_IDLE_UP);
		break;
	case ANIMATION_WALK_RIGHT:
		changeSprite(ANIMATION_IDLE_RIGHT);
		break;
	case ANIMATION_WALK_DOWN:
		changeSprite(ANIMATION_IDLE_DOWN);
		break;
	case ANIMATION_WALK_LEFT:
		changeSprite(ANIMATION_IDLE_LEFT);
		break;
	}
}


// Changes the sprite animation to the melee attack for one animation then returns back to idle
void Character::playMeleeAttackAnimation(float rotation)
{
	if (rotation < 90)
	{
		changeSprite(ANIMATION_ATTACK_MELEE, ANIMATION_WALK_RIGHT);
	}
	else if (rotation < 180)
	{
		changeSprite(ANIMATION_ATTACK_MELEE, ANIMATION_WALK_DOWN);
	}
	else if (rotation < 270)
	{
		changeSprite(ANIMATION_ATTACK_MELEE, ANIMATION_WALK_LEFT);
	}
	else
	{
		changeSprite(ANIMATION_ATTACK_MELEE, ANIMATION_WALK_UP);
	}
}


// Changes the sprite animation to the range attack for one animation then returns back to idle
void Character::playRangeAttackAnimation(float rotation)
{
	if (rotation < 90)
	{
		changeSprite(ANIMATION_ATTACK_RANGE, ANIMATION_WALK_RIGHT);
	}
	else if (rotation < 180)
	{
		changeSprite(ANIMATION_ATTACK_RANGE, ANIMATION_WALK_DOWN);
	}
	else if (rotation < 270)
	{
		changeSprite(ANIMATION_ATTACK_RANGE, ANIMATION_WALK_LEFT);
	}
	else
	{
		changeSprite(ANIMATION_ATTACK_RANGE, ANIMATION_WALK_UP);
	}
}

void Character::playHurtAnimation(float rotation)
{
	if (rotation < 90)
	{
		changeSprite(ANIMATION_HURT, ANIMATION_WALK_RIGHT);
	}
	else if (rotation < 180)
	{
		changeSprite(ANIMATION_HURT, ANIMATION_WALK_DOWN);
	}
	else if (rotation < 270)
	{
		changeSprite(ANIMATION_HURT, ANIMATION_WALK_LEFT);
	}
	else
	{
		changeSprite(ANIMATION_HURT, ANIMATION_WALK_UP);
	}
}