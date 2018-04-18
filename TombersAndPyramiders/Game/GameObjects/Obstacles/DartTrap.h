#pragma once

#include "ComplexSprite.h"
#include "Vector2.h"
#include "Obstacle.h"

class DartTrap : public Obstacle
{
	public:
	DartTrap(Direction direction, Mode mode, float startX, float startY, float scale) : Obstacle(createSpriteInfo(direction), new Vector2(0, 0), direction, mode, startX, startY, scale) {

	}
	std::shared_ptr<ComplexSpriteInfo> createSpriteInfo(Direction direction);

	private:
	Mode m_mode;
};