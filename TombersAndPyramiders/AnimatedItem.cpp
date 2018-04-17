#include "AnimatedItem.h"


AnimatedItem::AnimatedItem(std::shared_ptr<ComplexSpriteInfo> spriteInfo): ComplexSprite(spriteInfo, 0, 0)
{

}

//std::shared_ptr<ComplexSpriteInfo> AnimatedItem::createSpriteInfo()
//{
//	auto spriteInfo = std::make_shared<ComplexSpriteInfo>();
//	spriteInfo->addSprite("boulderRolling.png", "boulderRolling", 8, 2);
//	return spriteInfo;
//}


AnimatedItem::~AnimatedItem()
{
}
