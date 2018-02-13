#include "HostCharacter.h"
#include "CharacterController.h"
#include "Inventory.h"
#include "Receiver.h"

HostCharacter::HostCharacter(BasePilot* basePilot, int networkingID) :
	Character(basePilot)
{
	setFPS(12);
	addComponent<Inventory>(this);
	addComponent<CharacterController>(this, getComponent<Inventory>().get(), basePilot);
	std::shared_ptr<Receiver> receiver = addComponent<Receiver>(this, std::to_string(networkingID));
	receiver->Subscribe("ATTACK", [](std::map<std::string, void*> data) -> void 
	{
		((HostCharacter*)data["this"])->getComponent<CharacterController>()->useWeapon();
	}, this);
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
void HostCharacter::onUpdate(int ticks)
{
	updateFrames(ticks);
}

// Private generation logic for describing the sprite sheet relationships for this player
std::shared_ptr<ComplexSpriteinfo> HostCharacter::generateComplexSpriteInfo()
{
	std::shared_ptr<ComplexSpriteinfo> spriteInfo = std::make_shared<ComplexSpriteinfo>();

	spriteInfo->addInfo("squareIdle.png", 8, 1);
	spriteInfo->addInfo("squareRun.png", 8, 1);
	spriteInfo->addInfo("squareRedAttack.png", 8, 1);
	spriteInfo->addInfo("squareWhiteAttack.png", 8, 1);

	return spriteInfo;
}

// Changes the sprite animation to running
void HostCharacter::playRunAnimation()
{
	changeSprite(ANIMATION_RUN);
}


// Changes the sprite animation to idling
void HostCharacter::endRunAnimation()
{
	changeSprite(ANIMATION_IDLE);
}


// Changes the sprite animation to the melee attack for one animation then returns back to idle
void HostCharacter::playMeleeAttackAnimation()
{
	changeSprite(ANIMATION_ATTACK_MELEE, ANIMATION_IDLE);
}


// Changes the sprite animation to the range attack for one animation then returns back to idle
void HostCharacter::playRangeAttackAnimation()
{
	changeSprite(ANIMATION_ATTACK_RANGE, ANIMATION_IDLE);
}
