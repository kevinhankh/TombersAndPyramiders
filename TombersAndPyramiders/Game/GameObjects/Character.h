/*===================================================================================*//**
	Character
	
	Prefab class for any character.
    
    Copyright 2017 Erick Fernandez de Arteaga. All rights reserved.
        https://www.linkedin.com/in/erick-fda
        https://bitbucket.org/erick-fda
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "SimpleSprite.h"
#include "BoxCollider.h"
#include "ComplexSprite.h"
#include "BasePilot.h"

/*========================================================================================
Character Types
========================================================================================*/
enum CharacterType
{
	player,
	beetle,
	MAX
};

/*========================================================================================
	Player Animation Defines
========================================================================================*/
#define ANIMATION_WALK_UP 0
#define ANIMATION_WALK_RIGHT 1
#define ANIMATION_WALK_DOWN 2
#define ANIMATION_WALK_LEFT 3
#define ANIMATION_IDLE_UP 4
#define ANIMATION_IDLE_RIGHT 5
#define ANIMATION_IDLE_DOWN 6
#define ANIMATION_IDLE_LEFT 7
#define ANIMATION_HURT_UP 8
#define ANIMATION_HURT_RIGHT 9
#define ANIMATION_HURT_DOWN 10
#define ANIMATION_HURT_LEFT 11
#define ANIMATION_ATTACK_MELEE 12
#define ANIMATION_ATTACK_RANGE 13
#define ANIMATION_HURT 14
#define ANIMATION_WALK 15
#define ANIMATION_IDLE 16

/*========================================================================================
	Character	
========================================================================================*/
class Character : public ComplexSprite
{
    /*----------------------------------------------------------------------------------------
		Instance Fields
    ----------------------------------------------------------------------------------------*/
    private:
		BoxCollider* m_boxCollider = nullptr;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit Character(BasePilot* basePilot, CharacterType type = player);

	/*----------------------------------------------------------------------------------------
		Instance Getter Methods
    ----------------------------------------------------------------------------------------*/
    public:
        
    
	/*----------------------------------------------------------------------------------------
		Instance Setter Methods
	----------------------------------------------------------------------------------------*/
    public:


	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
    public:
		void onUpdate(int ticks);
		bool playAnimation(int animID, int animReturn = -1);
		bool playRunAnimation();
		bool endRunAnimation();
		bool playMeleeAttackAnimation();
		bool playRangeAttackAnimation();
		bool playHurtAnimation();
		virtual void onEnd () {};
		virtual void onNetworkEnd () {};

    private:
		/*--------------------
		Player Animation Logic
		--------------------*/
		std::shared_ptr<ComplexSpriteinfo> generateComplexSpriteInfo(CharacterType type = player);
};
