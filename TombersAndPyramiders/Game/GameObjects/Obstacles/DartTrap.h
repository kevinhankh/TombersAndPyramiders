#pragma once

#include "ComplexSprite.h"
#include "Vector2.h"
#include "Obstacle.h"

class DartTrap : public Obstacle
{
	public:
	DartTrap(Direction direction, Mode mode, float startX, float startY, float scale) : Obstacle(createSpriteInfo(direction), createColliderOffset(direction, scale), direction, mode, startX, startY, scale) {

	}
	std::shared_ptr<ComplexSpriteInfo> createSpriteInfo(Direction direction);
	void setState(Mode mode);

	private:
	Mode m_mode;
};