#pragma once

#include <memory>
#include "MiscSquare.h"
#include "MovingSquare.h"
#include "NetworkCharacter.h"
#include "Character.h"

class SpawnManager
{
private:
	static SpawnManager* s_instance;
	//GameObject* mGameObj;

	SpawnManager();
	~SpawnManager();

	//Networking test
	std::vector<std::shared_ptr<NetworkCharacter>> networkCharacters;

public:
	std::shared_ptr<MiscSquare> generateMiscSquare(float x, float y, float scale);
	std::shared_ptr<MovingSquare> generateMovingSquare(float x, float y);

	//Networking test
	std::shared_ptr<NetworkCharacter> generateNetworkCharacter(float x, float y);

	std::shared_ptr<Character> generatePlayerCharacter(float x, float y);

	static SpawnManager* getInstance();
};