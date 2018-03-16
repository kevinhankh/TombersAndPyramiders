#pragma once

#include "ComplexSprite.h"

class Door : public ComplexSprite
{
public:
	enum Direction { West, East, North, South };
	enum Mode { Open = 0, Closed = 1};
	enum Animation { Opening = 2, Closing = 3 };

	Door(std::shared_ptr<ComplexSpriteinfo> spriteInfo, Direction direction, Mode mode = Closed, float startX = 0.0f, float startY = 0.0f);
	
	void onStart() {};
	void onUpdate(int ticks);
	void onEnd() {};

	Mode getState(); 
	void setState(Mode mode);

protected:
	virtual std::shared_ptr<ComplexSpriteinfo> createSpriteInfo(Direction direction) = 0;

private:
	Mode m_mode;
};