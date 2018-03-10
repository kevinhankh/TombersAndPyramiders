#pragma once

#include "SimpleSprite.h"

extern class BasePilot;

class GhostCharacter : public SimpleSprite
{
private:

public:
	GhostCharacter(BasePilot* pilot);
	~GhostCharacter();

	void onStart();
	void onUpdate(int ticks) {};
	void onEnd() {};

};