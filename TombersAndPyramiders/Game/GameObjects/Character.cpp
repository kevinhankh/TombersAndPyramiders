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

	currentState = IDLE_UP;
	changeSpriteSheet("m_walk");
	changeAnimation("IdleUp");
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
std::shared_ptr<ComplexSpriteInfo> Character::generateComplexSpriteInfo(CharacterType type)
{
	std::shared_ptr<ComplexSpriteInfo> spriteInfo = std::make_shared<ComplexSpriteInfo>();

	switch (type)
	{
	case player:
		//spriteInfo->addSprite("Player/Walk/tanm_walk_up.png", "tanm_walk_up", 9, 1);
		//spriteInfo->addSprite("Player/Walk/tanm_walk_right.png", "tanm_walk_right", 9, 1);
		//spriteInfo->addSprite("Player/Walk/tanm_walk_down.png", "tanm_walk_down", 9, 1);
		//spriteInfo->addSprite("Player/Walk/tanm_walk_left.png", "tanm_walk_left", 9, 1);
		//spriteInfo->addSprite("Player/Idle/tanm_idle_up.png", "tanm_idle_up", 1, 1);
		//spriteInfo->addSprite("Player/Idle/tanm_idle_right.png", "tanm_idle_right", 1, 1);
		//spriteInfo->addSprite("Player/Idle/tanm_idle_down.png", "tanm_idle_down", 1, 1);
		//spriteInfo->addSprite("Player/Idle/tanm_idle_left.png", "tanm_idle_left", 1, 1);
		//spriteInfo->addSprite("Player/Die/tanm_hurt_up.png", "tanm_hurt_up", 1, 1);
		//spriteInfo->addSprite("Player/Die/tanm_hurt_down.png", "tanm_hurt_down", 1, 1);
		//spriteInfo->addSprite("Player/Die/tanm_hurt_left.png", "tanm_hurt_left", 1, 1);
		//spriteInfo->addSprite("Player/Die/tanm_hurt_right.png", "tanm_hurt_right", 1, 1);
		spriteInfo->addSprite("Player/Walk/m_walk.png", "m_walk", 9, 4);
		spriteInfo->addAnimation("m_walk", "WalkUp", 1, 8);
		spriteInfo->addAnimation("m_walk", "WalkLeft", 10, 17);
		spriteInfo->addAnimation("m_walk", "WalkDown", 19, 26);
		spriteInfo->addAnimation("m_walk", "WalkRight", 28, 35);
		spriteInfo->addAnimation("m_walk", "IdleUp", 0, 0);
		spriteInfo->addAnimation("m_walk", "IdleLeft", 9, 9);
		spriteInfo->addAnimation("m_walk", "IdleDown", 18, 18);
		spriteInfo->addAnimation("m_walk", "IdleRight", 27, 27);

		spriteInfo->addSprite("Player/Attack/Melee/m_melee_slash.png", "m_melee_slash", 6, 4);
		spriteInfo->addAnimation("m_melee_slash", "SlashUp", 1, 5);
		spriteInfo->addAnimation("m_melee_slash", "SlashLeft", 7, 11);
		spriteInfo->addAnimation("m_melee_slash", "SlashDown", 13, 17);
		spriteInfo->addAnimation("m_melee_slash", "SlashRight", 19, 23);
		spriteInfo->addAnimation("m_melee_slash", "IdleUp", 0, 0);
		spriteInfo->addAnimation("m_melee_slash", "IdleLeft", 6, 6);
		spriteInfo->addAnimation("m_melee_slash", "IdleDown", 12, 12);
		spriteInfo->addAnimation("m_melee_slash", "IdleRight", 18, 18);

		spriteInfo->addSprite("Player/Attack/Bow/m_bow.png", "m_bow", 13, 4);
		spriteInfo->addAnimation("m_bow", "BowUp", 1, 12);
		spriteInfo->addAnimation("m_bow", "BowLeft", 14, 25);
		spriteInfo->addAnimation("m_bow", "BowDown", 27, 38);
		spriteInfo->addAnimation("m_bow", "BowRight", 40, 51);
		spriteInfo->addAnimation("m_bow", "IdleUp", 0, 0);
		spriteInfo->addAnimation("m_bow", "IdleLeft", 13, 13);
		spriteInfo->addAnimation("m_bow", "IdleDown", 26, 26);
		spriteInfo->addAnimation("m_bow", "IdleRight", 39, 39);

		break;
	case beetle:
		spriteInfo->addSprite("beetle_walk_up.png", "beetle_walk_up", 3, 1);
		spriteInfo->addSprite("beetle_walk_right.png", "beetle_walk_right", 3, 1);
		spriteInfo->addSprite("beetle_walk_down.png", "beetle_walk_down", 3, 1);
		spriteInfo->addSprite("beetle_walk_left.png", "beetle_walk_left", 3, 1);
		spriteInfo->addSprite("beetle_idle_up.png", "beetle_idle_up", 1, 1);
		spriteInfo->addSprite("beetle_idle_right.png", "beetle_idle_right", 1, 1);
		spriteInfo->addSprite("beetle_idle_down.png", "beetle_idle_down", 1, 1);
		spriteInfo->addSprite("beetle_idle_left.png", "beetle_idle_left", 1, 1);
		spriteInfo->addSprite("beetle_hurt_up.png", "beetle_hurt_up", 1, 1);
		spriteInfo->addSprite("beetle_hurt_right.png", "beetle_hurt_right", 1, 1);
		spriteInfo->addSprite("beetle_hurt_down.png", "beetle_hurt_down", 1, 1);
		spriteInfo->addSprite("beetle_hurt_left.png", "beetle_hurt_left", 1, 1);
		break;
	}
	
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
		changeSpriteSheet("m_walk");
		changeAnimation("WalkRight");
		currentState = WALK_RIGHT;
		return true;
	}
	else if (rotation < 180)
	{
		changeSpriteSheet("m_walk");
		changeAnimation("WalkDown");
		currentState = WALK_DOWN;
		return true;
	}
	else if (rotation < 270)
	{
		changeSpriteSheet("m_walk");
		changeAnimation("WalkLeft");
		currentState = WALK_LEFT;
		return true;
	}
	else if (rotation >= 270 && rotation <= 360)
	{
		changeSpriteSheet("m_walk");
		changeAnimation("WalkUp");
		currentState = WALK_UP;
		return true;
	}

	return false;
}


// Changes the sprite animation to idling
bool Character::endRunAnimation()
{
	switch (currentState)
	{
		case WALK_UP:
			changeSpriteSheet("m_walk");
			changeAnimation("IdleUp");
			currentState = IDLE_UP;
			return true;
		case WALK_RIGHT:
			changeSpriteSheet("m_walk");
			changeAnimation("IdleRight"); 
			currentState = IDLE_RIGHT;
			return true;
		case WALK_DOWN:
			changeSpriteSheet("m_walk");
			changeAnimation("IdleDown"); 
			currentState = IDLE_DOWN;
			return true;
		case WALK_LEFT:
			changeSpriteSheet("m_walk");
			changeAnimation("IdleLeft"); 
			currentState = IDLE_LEFT;
			return true;
		//default:
		//	changeSpriteSheet("m_walk");
		//	changeAnimation("IdleUp"); 
		//	currentState = IDLE_UP;
		//	return true;
	}
	return false;
}


// Changes the sprite animation to the melee attack for one animation then returns back to idle
bool Character::playMeleeAttackAnimation()
{
	//float rotation = getTransform()->getRotation();
	//if (rotation < 90)
	//{
	//	changeSpriteSheet("m_melee_slash");
	//	changeAnimation("IdleLeft");
	//	currentState = IDLE_LEFT;
	//	changeSpriteSheet(getCurrentSpriteSheetIndex(), ANIMATION_IDLE_RIGHT);
	//}
	//else if (rotation < 180)
	//{
	//	changeSpriteSheet(getCurrentSpriteSheetIndex(), ANIMATION_IDLE_DOWN);
	//}
	//else if (rotation < 270)
	//{
	//	changeSpriteSheet(getCurrentSpriteSheetIndex(), ANIMATION_IDLE_LEFT);
	//}
	//else
	//{
	//	changeSpriteSheet(getCurrentSpriteSheetIndex(), ANIMATION_IDLE_UP);
	//}
	return true;
}

// Changes the sprite animation to the range attack for one animation then returns back to idle
bool Character::playRangeAttackAnimation()
{
	float rotation = getTransform()->getRotation();
	if (rotation < 90)
	{
		changeSpriteSheet("m_bow");
		changeAnimation("BowRight", "IdleRight");
		currentState = IDLE_RIGHT;
	}
	else if (rotation < 180)
	{
		changeSpriteSheet("m_bow");
		changeAnimation("BowDown", "IdleDown");
		currentState = IDLE_DOWN;
	}
	else if (rotation < 270)
	{
		changeSpriteSheet("m_bow");
		changeAnimation("BowLeft", "IdleLeft");
		currentState = IDLE_LEFT;
	}
	else
	{
		changeSpriteSheet("m_bow");
		changeAnimation("BowUp", "IdleUp");
		currentState = IDLE_UP;
	}

	return true;
}

bool Character::playHurtAnimation()
{
	//float rotation = getTransform()->getRotation();
	//if (rotation < 90)
	//{
	//	changeSpriteSheet(ANIMATION_HURT_RIGHT, ANIMATION_IDLE_RIGHT);
	//}
	//else if (rotation < 180)
	//{
	//	changeSpriteSheet(ANIMATION_HURT_DOWN, ANIMATION_IDLE_DOWN);
	//}
	//else if (rotation < 270)
	//{
	//	changeSpriteSheet(ANIMATION_HURT_LEFT, ANIMATION_IDLE_LEFT);
	//}
	//else
	//{
	//	changeSpriteSheet(ANIMATION_HURT_UP, ANIMATION_IDLE_UP);
	//}

	return true;
}

void Character::onNetworkEnd() 
{
}