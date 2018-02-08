#pragma once

#include <memory>
#include "MiscSquare.h"
#include "MovingSquare.h"

class SpawnManager
{
private:
	static SpawnManager* s_instance;
	//GameObject* mGameObj;

	SpawnManager();
	~SpawnManager();
	std::vector<std::shared_ptr<MiscSquare>> miscSquares;
	std::vector<std::shared_ptr<MovingSquare>> movingSquares;

public:
	std::shared_ptr<MiscSquare> generateMiscSquare(float x, float y, float scale);
	std::shared_ptr<MovingSquare> generateMovingSquare(float x, float y);
	static SpawnManager* getInstance();
};