#pragma once

#include "SimpleSprite.h"

class Tower : public SimpleSprite
{
private:

public:
	Tower();
	~Tower();

	void onStart() {};
	void onUpdate(int ticks) {}
	void onEnd() {};

};