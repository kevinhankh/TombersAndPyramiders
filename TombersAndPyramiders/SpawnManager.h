#pragma once

#include <memory>
#include "Wall.h"
#include "MiscSquare.h"
#include "MovingSquare.h"
#include "PlayerCharacter.h"
#include "DummyPlayerCharacter.h"

class SpawnManager
{
private:
	static SpawnManager* s_instance;
	//GameObject* mGameObj;

	SpawnManager();
	~SpawnManager();
	std::vector<std::shared_ptr<Wall>> walls;
	std::vector<std::shared_ptr<MiscSquare>> miscSquares;
	std::vector<std::shared_ptr<MovingSquare>> movingSquares;
	std::vector<std::shared_ptr<PlayerCharacter>> simpleCharacters;
	std::vector<std::shared_ptr<DummyPlayerCharacter>> dummySimpleCharacters;

public:
	std::shared_ptr<Wall> generateWall(float x, float y, float scale);
	std::shared_ptr<MiscSquare> generateMiscSquare(float x, float y, float scale);
	std::shared_ptr<MovingSquare> generateMovingSquare(float x, float y);
	std::shared_ptr<PlayerCharacter> generateSimpleCharacter(float x, float y);
	std::shared_ptr<DummyPlayerCharacter> generateDummySimpleCharacter(float x, float y);
	static SpawnManager* getInstance();
};