#pragma once
#include "ComplexSprite.h"

class AnimatedItem : public ComplexSprite
{
public:
	AnimatedItem(std::shared_ptr<ComplexSpriteInfo> spriteInfo);
	~AnimatedItem();

	//std::shared_ptr<ComplexSpriteInfo> createSpriteInfo();
};

