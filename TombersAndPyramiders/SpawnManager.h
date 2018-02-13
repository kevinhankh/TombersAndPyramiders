#pragma once

#include <memory>
#include "MiscSquare.h"
#include "MovingSquare.h"
#include "NetworkCharacter.h"
#include "Character.h"
#include "HostCharacter.h"
#include "ClientCharacter.h"

class SpawnManager : public GameObject
{
private:
	static std::shared_ptr<SpawnManager> s_instance;
	//GameObject* mGameObj;


public:
	SpawnManager ();
	~SpawnManager ();
	std::shared_ptr<MiscSquare> generateMiscSquare(float x, float y, float scale);
	std::shared_ptr<MovingSquare> generateMovingSquare(float x, float y);

	//Networking test
	std::shared_ptr<HostCharacter> generateNetworkCharacter(Uint32 ip, float x, float y);

	std::shared_ptr<ClientCharacter> generatePlayerCharacter(Uint32 ip, float x, float y);
	void sendStartPacket ();

	static std::shared_ptr<SpawnManager> getInstance();
};