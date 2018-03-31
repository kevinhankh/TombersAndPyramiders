#include "Sender.h"
#include "NetworkingManager.h"
#include "CharacterController.h"
#include "GhostController.h"
#include "GhostPilot.h"

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
	payload["z"] = std::to_string (transform->getZ ());
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
	Transform* transform = gameObject->getTransform ();
	Vector2 lastMovementVector;
	std::shared_ptr<CharacterController> cc = gameObject->getComponent<CharacterController> ();
	if (cc != nullptr) 
	{
		PlayerPilot* pp = (PlayerPilot*)cc->getPilot();
		lastMovementVector = Vector2(pp->m_lastMoveVector.getX(), pp->m_lastMoveVector.getY());
	}
	else {
		std::shared_ptr<GhostController> gc = gameObject->getComponent<GhostController>();
		auto gp = (GhostPilot*)gc->getPilot();
		lastMovementVector = Vector2(gp->getLastMovement().getX(), gp->getLastMovement().getY());
	}
	payload["x"] = std::to_string(transform->getX());
	payload["y"] = std::to_string(transform->getY());
	payload["z"] = std::to_string (transform->getZ ());
	payload["vecX"] = std::to_string (lastMovementVector.getX());
	payload["vecY"] = std::to_string (lastMovementVector.getY());
	payload["rotation"] = std::to_string(transform->getRotation());
	payload["scale"] = std::to_string(transform->getScale());
	sendNetworkMessage("UPDATE", payload, false);
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
	std::map<std::string, std::string> payload;
	payload["animID"] = std::to_string (animID);
	payload["animReturn"] = std::to_string (animReturn);
	sendNetworkMessage ("ANIMATE", payload);
}

void Sender::sendHurt (int newHP)
{
	std::map<std::string, std::string> payload;
	payload["newHealth"] = std::to_string (newHP);
	sendNetworkMessage ("HURT", payload);
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

void Sender::sendNetworkMessage(std::string messageKey, std::map<std::string, std::string> payload, bool useTCP)
{
	if (NetworkingManager::getInstance ()->inGame ()) {
		std::remove_if (messageKey.begin (), messageKey.end (), ::isspace); //::isspace lets it know to use std::isspace override as theres multiple
		if (useTCP)
			NetworkingManager::getInstance ()->prepareMessageForSendingTCP (m_id, messageKey, payload);
		else
			NetworkingManager::getInstance ()->prepareMessageForSendingUDP (m_id, messageKey, payload);
	}
}

Sender::~Sender()
{
	std::map<std::string, std::string> payload;
}

void Sender::onUpdate (int ticks)
{
	m_lastUpdate += ticks;
	if (m_lastUpdate >= 80) {
		sendUpdate ();
		m_lastUpdate = 0;
	}
}

int Sender::getNetworkID() {
	return m_id;
}