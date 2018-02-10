/*===================================================================================*//**
	PlayerCharacter
	
	Prefab class for the player character.
    
    Copyright 2017 Erick Fernandez de Arteaga. All rights reserved.
        https://www.linkedin.com/in/erick-fda
        https://bitbucket.org/erick-fda
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "PlayerCharacter.h"
#include "CharacterController.h"
#include "Inventory.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
PlayerCharacter::PlayerCharacter() :
	ComplexSprite(generateComplexSpriteInfo(), 0, 0)
{
	addComponent<CharacterController*>(new CharacterController(this));
	addComponent<Inventory*>(new Inventory(this));
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
void PlayerCharacter::onUpdate(int ticks)
{
	nextFrame();
}

// Private generation logic for describing the sprite sheet relationships for this player
std::shared_ptr<ComplexSpriteinfo> PlayerCharacter::generateComplexSpriteInfo()
{
	std::shared_ptr<ComplexSpriteinfo> spriteInfo = std::make_shared<ComplexSpriteinfo>();

	spriteInfo->addInfo("squareIdle.png", 8, 1);
	spriteInfo->addInfo("squareRun.png", 8, 1);
	spriteInfo->addInfo("squareRedAttack.png", 8, 1);
	spriteInfo->addInfo("squareWhiteAttack.png", 8, 1);

	return spriteInfo;
}

void PlayerCharacter::playRunAnimation()
{
	changeSprite(ANIMATION_RUN);
}

void PlayerCharacter::endRunAnimation()
{
	changeSprite(ANIMATION_IDLE);
}

void PlayerCharacter::playMeleeAttackAnimation()
{
	changeSprite(ANIMATION_ATTACK_MELEE, ANIMATION_IDLE);
}

void PlayerCharacter::playRangeAttackAnimation()
{
	changeSprite(ANIMATION_ATTACK_RANGE, ANIMATION_IDLE);
}