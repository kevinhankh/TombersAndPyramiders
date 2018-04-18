#pragma once

#include "ComplexSprite.h"
#include "Vector2.h"
#include "Obstacle.h"

class Spikes : public Obstacle
{
	public:
	Spikes(Direction direction, Mode mode, float startX, float startY, float scale) : Obstacle(createSpriteInfo(), new Vector2(0, 0), direction, mode, startX, startY, scale) {

	}
	std::shared_ptr<ComplexSpriteInfo> createSpriteInfo();

	private:
	Mode m_mode;
};