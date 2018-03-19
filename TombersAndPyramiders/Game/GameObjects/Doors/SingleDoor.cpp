#include "SingleDoor.h"

SingleDoor::SingleDoor(Door::Direction direction, Door::Mode mode, float startX, float startY) : Door(createSpriteInfo(direction), direction, mode, startX, startY)
{

}

std::shared_ptr<ComplexSpriteinfo> SingleDoor::createSpriteInfo(Direction direction)
{
	std::shared_ptr<ComplexSpriteinfo> spriteInfo = std::make_shared<ComplexSpriteinfo>();
	switch (direction)
	{
	case Door::West:
		spriteInfo->addInfo("stoneWallGateOpen_W.png", 1, 1);
		spriteInfo->addInfo("stoneWallGateClosed_W.png", 1, 1);
		spriteInfo->addInfo("stoneWallGateOpen_W.png", 1, 1); //Opening
		spriteInfo->addInfo("stoneWallGateClosed_W.png", 1, 1); //Closing
		break;
	case Door::East:
		spriteInfo->addInfo("stoneWallGateOpen_E.png", 1, 1);
		spriteInfo->addInfo("stoneWallGateClosed_E.png", 1, 1);
		spriteInfo->addInfo("stoneWallGateOpen_E.png", 1, 1); //Opening
		spriteInfo->addInfo("stoneWallGateClosed_E.png", 1, 1); //Closing
		break;
	case Door::North:
		spriteInfo->addInfo("stoneWallGateOpen_N.png", 1, 1);
		spriteInfo->addInfo("stoneWallGateClosed_N.png", 1, 1);
		spriteInfo->addInfo("stoneWallGateOpen_N.png", 1, 1); //Opening
		spriteInfo->addInfo("stoneWallGateClosed_N.png", 1, 1); //Closing
		break;
	case Door::South:
		spriteInfo->addInfo("stoneWallGateOpen_S.png", 1, 1);
		spriteInfo->addInfo("stoneWallGateClosed_S.png", 1, 1);
		spriteInfo->addInfo("stoneWallGateOpen_S.png", 1, 1); //Opening
		spriteInfo->addInfo("stoneWallGateClosed_S.png", 1, 1); //Closing
		break;
	default:
		break;
	}
	return spriteInfo;
}