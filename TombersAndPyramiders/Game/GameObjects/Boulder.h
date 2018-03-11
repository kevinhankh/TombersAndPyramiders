#pragma once

#include "SimpleSprite.h"

class Boulder : public SimpleSprite
{
private:

public:
	Boulder(BasePilot* pilot);
	~Boulder();

	void onStart() {};
	void onUpdate(int ticks) {}
	void onEnd() {};

};