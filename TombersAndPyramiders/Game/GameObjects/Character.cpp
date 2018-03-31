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
#include "Sender.h"
#include "Receiver.h"
#include "SpawnManager.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
Character::Character(BasePilot* basePilot, CharacterType type) :
	ComplexSprite(generateComplexSpriteInfo(type), 0, 0)
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
std::shared_ptr<ComplexSpriteinfo> Character::generateComplexSpriteInfo(CharacterType type)
{
	std::shared_ptr<ComplexSpriteinfo> spriteInfo = std::make_shared<ComplexSpriteinfo>();

	switch (type)
	{
	case player:
		spriteInfo->addInfo("tanm_walk_up.png", 9, 1);
		spriteInfo->addInfo("tanm_walk_right.png", 9, 1);
		spriteInfo->addInfo("tanm_walk_down.png", 9, 1);
		spriteInfo->addInfo("tanm_walk_left.png", 9, 1);
		spriteInfo->addInfo("tanm_idle_up.png", 1, 1);
		spriteInfo->addInfo("tanm_idle_right.png", 1, 1);
		spriteInfo->addInfo("tanm_idle_down.png", 1, 1);
		spriteInfo->addInfo("tanm_idle_left.png", 1, 1);
		spriteInfo->addInfo("tanm_hurt_up.png", 1, 1);
		spriteInfo->addInfo("tanm_hurt_down.png", 1, 1);
		spriteInfo->addInfo("tanm_hurt_left.png", 1, 1);
		spriteInfo->addInfo("tanm_hurt_right.png", 1, 1);
		break;
	case beetle:
		spriteInfo->addInfo("beetle_walk_up.png", 3, 1);
		spriteInfo->addInfo("beetle_walk_right.png", 3, 1);
		spriteInfo->addInfo("beetle_walk_down.png", 3, 1);
		spriteInfo->addInfo("beetle_walk_left.png", 3, 1);
		spriteInfo->addInfo("beetle_idle_up.png", 1, 1);
		spriteInfo->addInfo("beetle_idle_right.png", 1, 1);
		spriteInfo->addInfo("beetle_idle_down.png", 1, 1);
		spriteInfo->addInfo("beetle_idle_left.png", 1, 1);
		spriteInfo->addInfo("beetle_hurt_up.png", 1, 1);
		spriteInfo->addInfo("beetle_hurt_right.png", 1, 1);
		spriteInfo->addInfo("beetle_hurt_down.png", 1, 1);
		spriteInfo->addInfo("beetle_hurt_left.png", 1, 1);
		break;
	default:
		spriteInfo->addInfo("tanm_walk_up.png", 9, 1);
		spriteInfo->addInfo("tanm_walk_right.png", 9, 1);
		spriteInfo->addInfo("tanm_walk_down.png", 9, 1);
		spriteInfo->addInfo("tanm_walk_left.png", 9, 1);
		spriteInfo->addInfo("tanm_idle_up.png", 1, 1);
		spriteInfo->addInfo("tanm_idle_right.png", 1, 1);
		spriteInfo->addInfo("tanm_idle_down.png", 1, 1);
		spriteInfo->addInfo("tanm_idle_left.png", 1, 1);
		spriteInfo->addInfo("tanm_hurt_up.png", 1, 1);
		spriteInfo->addInfo("tanm_hurt_down.png", 1, 1);
		spriteInfo->addInfo("tanm_hurt_left.png", 1, 1);
		spriteInfo->addInfo("tanm_hurt_right.png", 1, 1);
		break;
	}


	//spriteInfo->addInfo("squareRedAttack.png", 8, 1);
	//spriteInfo->addInfo("squareWhiteAttack.png", 8, 1);
	//spriteInfo->addInfo("squareHurt.png", 8, 1);
	
	return spriteInfo;
}

// Changes the sprite to the specified ID
bool Character::playAnimation(int animID, int animReturn)
{
	if (animReturn != -1) 
	{
		if (animID == ANIMATION_ATTACK_MELEE)
		{
			playMeleeAttackAnimation();
		}
		else if (animID == ANIMATION_ATTACK_RANGE)
		{
			playRangeAttackAnimation();
		}
		else if (animID == ANIMATION_HURT)
		{
			playHurtAnimation();
		}
		else
		{
			return false;
		}
	}
	else 
	{
		if (animID == ANIMATION_WALK)
		{
			playRunAnimation();
		}
		else
		{
			endRunAnimation();
		}
	}
	return true;
}

// Changes the sprite animation to running
bool Character::playRunAnimation()
{
	float rotation = getTransform()->getRotation();

	if (rotation < 90)
	{
		changeSprite(ANIMATION_WALK_RIGHT);
		return true;
	}
	else if (rotation < 180)
	{
		changeSprite(ANIMATION_WALK_DOWN);
		return true;
	}
	else if (rotation < 270)
	{
		changeSprite(ANIMATION_WALK_LEFT);
		return true;
	}
	else
	{
		changeSprite(ANIMATION_WALK_UP);
		return true;
	}

	return false;
}


// Changes the sprite animation to idling
bool Character::endRunAnimation()
{
	switch (getCurrentSprite())
	{
		case ANIMATION_WALK_UP:
			changeSprite(ANIMATION_IDLE_UP);
			return true;
			break;
		case ANIMATION_WALK_RIGHT:
			changeSprite(ANIMATION_IDLE_RIGHT);
			return true;
			break;
		case ANIMATION_WALK_DOWN:
			changeSprite(ANIMATION_IDLE_DOWN);
			return true;
			break;
		case ANIMATION_WALK_LEFT:
			changeSprite(ANIMATION_IDLE_LEFT);
			return true;
			break;
	}
	return false;
}


// Changes the sprite animation to the melee attack for one animation then returns back to idle
bool Character::playMeleeAttackAnimation()
{
	float rotation = getTransform()->getRotation();
	if (rotation < 90)
	{
		changeSprite(getCurrentSprite(), ANIMATION_IDLE_RIGHT);
	}
	else if (rotation < 180)
	{
		changeSprite(getCurrentSprite(), ANIMATION_IDLE_DOWN);
	}
	else if (rotation < 270)
	{
		changeSprite(getCurrentSprite(), ANIMATION_IDLE_LEFT);
	}
	else
	{
		changeSprite(getCurrentSprite(), ANIMATION_IDLE_UP);
	}
	return true;
}

// Changes the sprite animation to the range attack for one animation then returns back to idle
bool Character::playRangeAttackAnimation()
{
	float rotation = getTransform()->getRotation();
	if (rotation < 90)
	{
		changeSprite(getCurrentSprite(), ANIMATION_IDLE_RIGHT);
	}
	else if (rotation < 180)
	{
		changeSprite(getCurrentSprite(), ANIMATION_IDLE_DOWN);
	}
	else if (rotation < 270)
	{
		changeSprite(getCurrentSprite(), ANIMATION_IDLE_LEFT);
	}
	else
	{
		changeSprite(getCurrentSprite(), ANIMATION_IDLE_UP);
	}

	return true;
}

bool Character::playHurtAnimation()
{
	float rotation = getTransform()->getRotation();
	if (rotation < 90)
	{
		changeSprite(ANIMATION_HURT_RIGHT, ANIMATION_IDLE_RIGHT);
	}
	else if (rotation < 180)
	{
		changeSprite(ANIMATION_HURT_DOWN, ANIMATION_IDLE_DOWN);
	}
	else if (rotation < 270)
	{
		changeSprite(ANIMATION_HURT_LEFT, ANIMATION_IDLE_LEFT);
	}
	else
	{
		changeSprite(ANIMATION_HURT_UP, ANIMATION_IDLE_UP);
	}

	return true;
}

void Character::onNetworkEnd() {
	auto receiver = getComponent<Receiver>();
	if (receiver != nullptr) {
		SpawnManager::getInstance()->generateNetworkGhost(getTransform()->getX(), getTransform()->getY(), receiver->netID, false);
	}
}