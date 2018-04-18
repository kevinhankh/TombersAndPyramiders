#include <memory>
#include "Spikes.h"

std::shared_ptr<ComplexSpriteInfo> Spikes::createSpriteInfo()
{
	std::shared_ptr<ComplexSpriteInfo> spriteInfo = std::make_shared<ComplexSpriteInfo>();
    spriteInfo->addSprite("Spikes.png", "Spikes", 1, 1);
	return spriteInfo;
}