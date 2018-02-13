#include "SpawnManager.h"
#include <vector>
#include "GameManager.h"
#include "Inventory.h"
#include "WoodenShortsword.h"
#include "WoodenLongbow.h"
#include "PlayerPilot.h"
#include "Receiver.h"
#include "Sender.h"
#include "NetworkingManager.h"
#include "NetworkedGameScene.h"
#include "NetworkCharacter.h"
#include "HostPilot.h"

std::shared_ptr<SpawnManager> SpawnManager::s_instance;

void callback(std::map<std::string, void*> payload)
{
	SpawnManager* self = (SpawnManager*)payload["this"];
	NetworkedGameScene* scene = new NetworkedGameScene ();
	SceneManager::getInstance ()->pushScene (scene);

	int players = std::stoi (*(std::string*)payload["playerSpawns"]);

	int id = std::stoi (*(std::string*)payload["playerSpawnIP0"]);
	float x = std::stof (*(std::string*)payload["playerSpawnX0"]);
	float y = std::stof (*(std::string*)payload["playerSpawnY0"]);

	SpawnManager::getInstance ()->generateNetworkCharacter (id, x, y);

	for (auto i = 1; i < players; i++) {
		id = std::stoi (*(std::string*)payload["playerSpawnIP" + std::to_string (i)]);
		x = std::stof (*(std::string*)payload["playerSpawnX" + std::to_string (i)]);
		y = std::stof (*(std::string*)payload["playerSpawnY" + std::to_string (i)]);
		
		scene->setCameraFollow (SpawnManager::getInstance ()->generatePlayerCharacter (id, x, y));
	}


}

void SpawnManager::sendStartPacket ()
{
	std::map<std::string, std::string> payload;

	NetworkedGameScene* scene = new NetworkedGameScene ();
	SceneManager::getInstance ()->pushScene (scene);

	payload["playerSpawns"] = std::to_string (NetworkingManager::getInstance ()->m_clients.size() + 1);

	int id = rand (), x = 0, y = -2;
	payload["playerSpawnIP0"] = std::to_string (id);
	payload["playerSpawnX0"] = std::to_string (x);
	payload["playerSpawnY0"] = std::to_string (y);
	scene->setCameraFollow (SpawnManager::getInstance ()->generatePlayerCharacter (id, x, y));

	int i = 1;
	for (auto it = NetworkingManager::getInstance ()->m_clients.begin (); it != NetworkingManager::getInstance ()->m_clients.end (); it++) {
		id = it->first;
		x = 2 * i;
		y = 2;
		payload["playerSpawnIP" + std::to_string(i)] = std::to_string (id);
		payload["playerSpawnX" + std::to_string (i)] = std::to_string (x);
		payload["playerSpawnY" + std::to_string (i)] = std::to_string (y);
		SpawnManager::getInstance ()->generateNetworkCharacter (id, x, y);
	}

	NetworkingManager::getInstance ()->prepareMessageForSending ("STARTGAME", payload);
}

std::shared_ptr<SpawnManager> SpawnManager::getInstance()
{
	if (s_instance == nullptr)
		s_instance = GameManager::getInstance()->createGameObject<SpawnManager> (true);
	return s_instance;
}

SpawnManager::SpawnManager() : GameObject()
{
	auto receiver = addComponent<Receiver>(this, std::to_string(getId()));
	MessageManager::subscribe ("STARTGAME", callback, this);
	auto sender = addComponent<Sender>(this, std::to_string(getId()));
}

SpawnManager::~SpawnManager()
{

}

std::shared_ptr<MiscSquare> SpawnManager::generateMiscSquare(float x, float y, float scale)
{
	std::shared_ptr<MiscSquare> miscSquare = GameManager::getInstance()->createGameObject<MiscSquare>(false);
	miscSquare->getTransform()->setPosition(x, y);
	miscSquare->getTransform()->setScale(scale);
	return miscSquare;
}

std	::shared_ptr<MovingSquare> SpawnManager::generateMovingSquare(float x, float y)
{
	std::shared_ptr<MovingSquare> movingSquare = GameManager::getInstance()->createGameObject<MovingSquare>(false);
	movingSquare->getTransform()->setPosition(x, y);
	return movingSquare;
}

std::shared_ptr<ClientCharacter> SpawnManager::generatePlayerCharacter(Uint32 ip, float x, float y)
{
	int id = ip;
	std::shared_ptr<ClientCharacter> simpleCharacter = GameManager::getInstance()->createGameObjectWithId<ClientCharacter>(false, id, new PlayerPilot());
	simpleCharacter->getComponent<Inventory>()->addItem(new WoodenLongbow());
	simpleCharacter->getTransform()->setPosition(x, y, 100);

	return simpleCharacter;
}

std::shared_ptr<HostCharacter> SpawnManager::generateNetworkCharacter(Uint32 ip, float x, float y)
{
	int id = ip;
	std::shared_ptr<HostCharacter> simpleCharacter = GameManager::getInstance()->createGameObjectWithId<HostCharacter>(false, id, new HostPilot ());
	simpleCharacter->getComponent<Inventory>()->addItem(new WoodenLongbow());
	simpleCharacter->getTransform()->setPosition(x, y, 100);
	return simpleCharacter;
}
/*
//Networking test
std::shared_ptr<NetworkCharacter> SpawnManager::generateNetworkCharacter(float x, float y)
{
	std::shared_ptr<NetworkCharacter> networkCharacter = std::shared_ptr<NetworkCharacter>(new NetworkCharacter());
	networkCharacter->getTransform()->setPosition(x, y);
	networkCharacters.push_back(networkCharacter);
	return networkCharacter;
}
*/