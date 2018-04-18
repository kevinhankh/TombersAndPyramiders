#include "DartTrap.h"
#include <memory>

std::shared_ptr<ComplexSpriteInfo> DartTrap::createSpriteInfo(Direction direction)
{
	std::shared_ptr<ComplexSpriteInfo> spriteInfo = std::make_shared<ComplexSpriteInfo>();
	switch (direction)
	{
	case Obstacle::West:
		spriteInfo->addSprite("DartTrapEnabled_W.png", "DartTrapEnabled_W", 1, 1);
		spriteInfo->addSprite("DartTrapDisabled_W.png", "DartTrapDisabled_W", 1, 1);
		break;
	case Obstacle::East:
		spriteInfo->addSprite("DartTrapEnabled_E.png", "DartTrapEnabled_E", 1, 1);
		spriteInfo->addSprite("DartTrapDisabled_E.png", "DartTrapDisabled_E", 1, 1);
		break;
	case Obstacle::North:
		spriteInfo->addSprite("DartTrapEnabled_N.png", "DartTrapEnabled_N", 1, 1);
		spriteInfo->addSprite("DartTrapDisabled_N.png", "DartTrapDisabled_N", 1, 1);
		break;
	case Obstacle::South:
		spriteInfo->addSprite("DartTrapEnabled_S.png", "DartTrapEnabled_S", 1, 1);
		spriteInfo->addSprite("DartTrapDisabled_S.png", "DartTrapDisabled_S", 1, 1);
		break;
	default:
		break;
	}
	return spriteInfo;
}

void DartTrap::setState(Mode mode)
{
	m_mode = mode;
	switch (m_mode)
	{
	case Obstacle::Enabled:
		changeSpriteSheet(Disabled);
		break;
	case Obstacle::Disabled:
		changeSpriteSheet(Enabled);
		break;
	default:
		break;
	}
}