#pragma once

#include "SimpleSprite.h"

class GhostCharacter : public SimpleSprite
{
private:

public:
	GhostCharacter();
	~GhostCharacter();

	void onStart() {};
	void onUpdate(int ticks) {}
	void onEnd() {};

};