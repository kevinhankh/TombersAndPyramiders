#include "SpawnManager.h"
#include <vector>
#include "GameManager.h"
#include "Inventory.h"
#include "WoodenShortsword.h"
#include "WoodenLongbow.h"
#include "PlayerPilot.h"
#include "AiPilot.h"
#include "DummyPilot.h"
#include "Receiver.h"
#include "Sender.h"
#include "NetworkingManager.h"
#include "NetworkedGameScene.h"
#include "NetworkCharacter.h"
#include "HostPilot.h"

std::shared_ptr<SpawnManager> SpawnManager::s_instance;

void startGameCallback(std::map<std::string, void*> payload)
{
	std::cout << "Client Start." << std::endl;

	SpawnManager* self = (SpawnManager*)payload["this"];
	NetworkedGameScene* scene = new NetworkedGameScene();
	SceneManager::getInstance()->pushScene(scene);

	int players = std::stoi(*(std::string*)payload["playerSpawns"]);

	int id = 0, x = 0, y = 0;
	for (int i = 0; i < players; i++) {
		id = std::stoi(*(std::string*)payload["playerSpawnIP" + std::to_string(i)]);
		x = std::stof(*(std::string*)payload["playerSpawnX" + std::to_string(i)]);
		y = std::stof(*(std::string*)payload["playerSpawnY" + std::to_string(i)]);
		if (NetworkingManager::getInstance ()->isSelf (id))
			scene->setCameraFollow (SpawnManager::getInstance ()->generatePlayerCharacter (id, x, y));
		else
			SpawnManager::getInstance ()->generateNetworkCharacter(id, x, y);
	}

	NetworkingManager::getInstance ()->startGameClient ();
	SpawnManager::getInstance ()->stopListeningForStartPacket ();
}

void SpawnManager::sendStartPacket()
{
	std::map<std::string, std::string> payload;

	NetworkedGameScene* scene = new NetworkedGameScene();
	SceneManager::getInstance()->pushScene(scene);

	payload["playerSpawns"] = std::to_string(NetworkingManager::getInstance()->m_clients.size());

	int id = 0, x = 0, y = 0;
	payload["playerSpawnIP0"] = std::to_string(id);
	payload["playerSpawnX0"] = std::to_string(x);
	payload["playerSpawnY0"] = std::to_string(y);
	scene->setCameraFollow(SpawnManager::getInstance()->generatePlayerCharacter(id, x, y));

	int i = 1;
	for (auto it = ++NetworkingManager::getInstance()->m_clients.begin(); it != NetworkingManager::getInstance()->m_clients.end(); it++) {
		id = it->first;
		x = 2 * i;
		y = 0;
		payload["playerSpawnIP" + std::to_string(i)] = std::to_string(id);
		payload["playerSpawnX" + std::to_string(i)] = std::to_string(x);
		payload["playerSpawnY" + std::to_string(i)] = std::to_string(y);
		SpawnManager::getInstance()->generateNetworkCharacter(id, x, y);
	}

	NetworkingManager::getInstance()->prepareMessageForSending("STARTGAME", payload);
}

void SpawnManager::listenForStartPacket()
{
	this->m_startPacketListenerID = MessageManager::subscribe("STARTGAME", startGameCallback, this);
}

void SpawnManager::stopListeningForStartPacket () {
	MessageManager::unSubscribe ("STARTGAME", m_startPacketListenerID);
}

std::shared_ptr<SpawnManager> SpawnManager::getInstance()
{
	if (s_instance == nullptr)
		s_instance = GameManager::getInstance()->createGameObject<SpawnManager>(true);
	return s_instance;
}

SpawnManager::SpawnManager() : GameObject()
{
	auto receiver = addComponent<Receiver>(this, std::to_string(getId()));
	auto sender = addComponent<Sender>(this, std::to_string(getId()));
}

std::shared_ptr<ClientCharacter> SpawnManager::generatePlayerCharacter(int id, float x, float y)
{
	std::shared_ptr<ClientCharacter> simpleCharacter = GameManager::getInstance()->createGameObjectWithId<ClientCharacter>(false, id, new PlayerPilot(), id);
	simpleCharacter->getComponent<Inventory>()->addItem(std::make_shared<WoodenLongbow>());
	simpleCharacter->getTransform()->setPosition(x, y, 100);

	return simpleCharacter;
}

std::shared_ptr<HostCharacter> SpawnManager::generateNetworkCharacter(int id, float x, float y)
{
	std::shared_ptr<HostCharacter> simpleCharacter = GameManager::getInstance()->createGameObjectWithId<HostCharacter>(false, id, new HostPilot(), id);
	simpleCharacter->getComponent<Inventory>()->addItem(std::make_shared<WoodenLongbow>());
	simpleCharacter->getTransform()->setPosition(x, y, 100);
	return simpleCharacter;
}

SpawnManager::~SpawnManager()
{

}

std::shared_ptr<MiscSquare> SpawnManager::generateMiscSquare(float x, float y, float z, float scale, string spriteName, bool hasCollider)
{
	std::shared_ptr<MiscSquare> miscSquare = GameManager::getInstance()->createGameObject<MiscSquare>(false, spriteName, hasCollider);
	miscSquare->getTransform()->setPosition(x, y, z);
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
	simpleCharacter->getComponent<Inventory>()->addItem(std::make_shared<WoodenShortsword>());
	simpleCharacter->getTransform()->setPosition(x, y);
	
	return simpleCharacter;
}

std::shared_ptr<Character> SpawnManager::generateAiCharacter(float x, float y)
{
	std::shared_ptr<Character> simpleAi = GameManager::getInstance()->createGameObject<Character>(false, new AiPilot());
	simpleAi->getComponent<Inventory>()->addItem(std::make_shared<WoodenLongbow>());
	simpleAi->getTransform()->setPosition(x, y);

	return simpleAi;
}

std::shared_ptr<Character> SpawnManager::generateDummyCharacter(float x, float y)
{
	std::shared_ptr<Character> simpleCharacter = GameManager::getInstance()->createGameObject<Character>(false, new DummyPilot());
	simpleCharacter->getComponent<Inventory>()->addItem(std::make_shared<WoodenShortsword>());
	simpleCharacter->getTransform()->setPosition(x, y);

	return simpleCharacter;
}

std::shared_ptr<WorldItem> SpawnManager::generateWorldItem(float x, float y, std::shared_ptr<BaseItem> item) 
{
	std::shared_ptr<WorldItem> worldItem = GameManager::getInstance()->createGameObject<WorldItem>(false, item, x, y);
	worldItem->addComponent<BoxCollider>(worldItem.get(), 1, 1)->setIsTrigger(true);
	return worldItem;
}

//std::shared_ptr<Wall> SpawnManager::generateWall(float x, float y, float scale)
//{
//	std::shared_ptr<Wall> wall = GameManager::getInstance()->createGameObject<Wall>(false);
//	wall->getTransform()->setPosition(x, y);
//	wall->getTransform()->setScale(scale);
//
//	return wall;
//}