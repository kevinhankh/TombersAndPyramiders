#include "Sender.h"
#include "NetworkingManager.h"

Sender::Sender(GameObject* gameObject, int ID) : Component(gameObject)
{
	this->m_id = ID;
}

void Sender::sendCreate()
{
	std::map<std::string, std::string> payload;
	Transform* transform = gameObject->getTransform();
	payload["x"] = std::to_string(transform->getX());
	payload["y"] = std::to_string(transform->getY());
	payload["z"] = std::to_string(transform->getZ());
	payload["rotation"] = std::to_string(transform->getRotation());
	payload["scale"] = std::to_string(transform->getScale());
	sendNetworkMessage("CREATE", payload);

}

void Sender::sendDestroy()
{
	std::map<std::string, std::string> payload;
	payload["ID"] = std::to_string(gameObject->getId());
	sendNetworkMessage("DESTROY", payload);
}

void Sender::sendUpdate()
{
	if (!NetworkingManager::getInstance ()->inGame ())
		return;
	std::map<std::string, std::string> payload;
	Transform* transform = gameObject->getTransform();
	payload["x"] = std::to_string(transform->getX());
	payload["y"] = std::to_string(transform->getY());
	payload["z"] = std::to_string(transform->getZ());
	payload["rotation"] = std::to_string(transform->getRotation());
	payload["scale"] = std::to_string(transform->getScale());
	sendNetworkMessage("UPDATE", payload);
}

void Sender::spawnPlayers(float p1x, float p1y, float p2x, float p2y)
{
	//Host tells reciever 
	std::map<std::string, std::string> payload;
	payload["p1x"] = p1x;
	payload["p1y"] = p1y;
	payload["p2x"] = p2x;
	payload["p2y"] = p2y;

	sendNetworkMessage("SPAWN", payload);
}

void Sender::sendAttack ()
{
	std::map<std::string, std::string> payload;
	sendNetworkMessage ("ATTACK", payload);
}

void Sender::sendAnimation (int animID, int animReturn)
{
	std::cout << "ANIMATE SENT " << std::endl;
	std::map<std::string, std::string> payload;
	payload["animID"] = std::to_string (animID);
	payload["animReturn"] = std::to_string (animReturn);
	sendNetworkMessage ("ANIMATE", payload);
}

void Sender::sendTrySwapItem ()
{
	std::map<std::string, std::string> payload;
	sendNetworkMessage ("TRYSWAPITEM", payload);
}

void Sender::sendSwappedItem ()
{
	std::map<std::string, std::string> payload;
	sendNetworkMessage ("SWAPPEDITEM", payload);
}

void Sender::sendTrigger()
{
	std::map<std::string, std::string> payload;
	sendNetworkMessage("TRIGGER", payload);
}

void Sender::sendNetworkMessage(std::string messageKey, std::map<std::string, std::string> payload)
{
	if (NetworkingManager::getInstance ()->inGame ()) {
		std::remove_if (messageKey.begin (), messageKey.end (), isspace);
		NetworkingManager::getInstance ()->prepareMessageForSending (m_id, messageKey, payload);
	}
}

Sender::~Sender()
{
	std::map<std::string, std::string> payload;
}

void Sender::onUpdate (int ticks)
{
	m_lastUpdate += ticks;
	if (m_lastUpdate >= 500) {
		sendUpdate ();
		m_lastUpdate = 0;
	}
}