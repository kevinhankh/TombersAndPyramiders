#include "GhostCharacter.h"
#include "GhostController.h"

GhostCharacter::GhostCharacter(BasePilot* pilot) : SimpleSprite("ghost.png", 0, 0)
{
	addComponent<GhostController>(this, pilot);
}

void GhostCharacter::onStart()
{
	std::cout << "GhostCharacter::onStart" << std::endl;
}


GhostCharacter::~GhostCharacter()
{

}