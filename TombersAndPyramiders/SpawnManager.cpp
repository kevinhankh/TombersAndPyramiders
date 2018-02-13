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

	int p1IP = std::stoi (*(std::string*)payload["playerSpawnIP0"]);
	float p1x = std::stof(*(std::string*)payload["playerSpawnX0"]);
	float p1y = std::stof(*(std::string*)payload["playerSpawnY0"]);

	int p2IP = std::stoi (*(std::string*)payload["playerSpawnIP1"]);
	float p2x = std::stof(*(std::string*)payload["playerSpawnX1"]);
	float p2y = std::stof(*(std::string*)payload["playerSpawnY1"]);

	std::cout << "IPC: " << p1IP << " - " << p2IP << std::endl;

	SpawnManager::getInstance ()->generateNetworkCharacter (p1IP, p1x, p1y);
	SpawnManager::getInstance ()->generatePlayerCharacter (p2IP, p2x, p2y);

}

void SpawnManager::sendStartPacket ()
{
	std::map<std::string, std::string> payload;

	int p1IP = rand();
	float p1x = -2;
	float p1y = -2;
	int p2IP = NetworkingManager::getInstance ()->m_clients.begin ()->first;
	float p2x = 2;
	float p2y = 2;

	std::cout << "IPH: " << p1IP << " - " << p2IP << std::endl;

	payload["playerSpawnIP0"] = std::to_string (p1IP);
	payload["playerSpawnX0"] = std::to_string (p1x);
	payload["playerSpawnY0"] = std::to_string (p1y);

	payload["playerSpawnIP1"] = std::to_string (p2IP);
	payload["playerSpawnX1"] = std::to_string (p2x);
	payload["playerSpawnY1"] = std::to_string (p2y);

	NetworkingManager::getInstance ()->prepareMessageForSending ("STARTGAME", payload);

	SpawnManager::getInstance ()->generatePlayerCharacter (p1IP, p1x, p1y);
	SpawnManager::getInstance ()->generateNetworkCharacter (p2IP, p2x, p2y);
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