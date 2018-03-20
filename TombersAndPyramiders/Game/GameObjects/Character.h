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
#define ANIMATION_ATTACK_MELEE 8
#define ANIMATION_ATTACK_RANGE 9
#define ANIMATION_HURT 10

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
        explicit Character(BasePilot* basePilot);

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
		void playRunAnimation(float rotation);
		void endRunAnimation(float rotation);
		void playMeleeAttackAnimation(float rotation);
		void playRangeAttackAnimation(float rotation);
		void playHurtAnimation(float rotation);
		virtual void onEnd () {};
		virtual void onNetworkEnd () {};
		bool playAnimation (int animID, int animReturn = -1);


    private:
		/*--------------------
		Player Animation Logic
		--------------------*/
		std::shared_ptr<ComplexSpriteinfo> generateComplexSpriteInfo();
};
