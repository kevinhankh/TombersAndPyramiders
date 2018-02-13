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

SpawnManager* SpawnManager::s_instance;

void callback(std::map<std::string, void*> payload)
{
	SpawnManager* self = (SpawnManager*)payload["this"];

	float p1x = std::stof(*(std::string*)payload["p1x"]);
	float p1y = std::stof(*(std::string*)payload["p1y"]);
	float p2x = std::stof(*(std::string*)payload["p2x"]);
	float p2y = std::stof(*(std::string*)payload["p2y"]);

	self->generateNetworkCharacter(p1x, p1y);
}

SpawnManager* SpawnManager::getInstance()
{
	if (s_instance == nullptr)
		s_instance = new SpawnManager();
	return s_instance;
}

SpawnManager::SpawnManager() : GameObject()
{
	auto receiver = addComponent<Receiver>(*(new Receiver(this, std::to_string(getId()))));
	receiver->Subscribe("SPAWN", callback, this);
	auto sender = addComponent<Sender>(*(new Sender(this, std::to_string(getId()))));
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

std::shared_ptr<Character> SpawnManager::generatePlayerCharacter(float x, float y)
{
	std::shared_ptr<Character> simpleCharacter = GameManager::getInstance()->createGameObject<Character>(false, new PlayerPilot());
	simpleCharacter->getComponent<Inventory>()->addItem(new WoodenLongbow());
	simpleCharacter->getTransform()->setPosition(x, y);

	return simpleCharacter;
}

std::shared_ptr<Character> SpawnManager::generateNetworkCharacter(float x, float y)
{
	IPaddress ip = NetworkingManager::getInstance()->getIP();
	int id = ip.host + rand();
	std::shared_ptr<Character> simpleCharacter = GameManager::getInstance()->createGameObject<Character>(false, id, new PlayerPilot());
	simpleCharacter->getComponent<Inventory>()->addItem(new WoodenLongbow());
	simpleCharacter->getTransform()->setPosition(x, y);
	simpleCharacter->addComponent<Receiver>(*(new Receiver(simpleCharacter.get(), std::to_string(id))));

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