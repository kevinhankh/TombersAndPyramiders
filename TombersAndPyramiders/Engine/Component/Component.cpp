#include "Component.h"
#include "GameManager.h"

Component::Component(GameObject* gameObject)
{
	this->gameObject = gameObject;
}

GameObject* Component::getGameObject()
{
	return gameObject;
}

Component::~Component() {}


void Component::destroy(std::shared_ptr<GameObject> gameObject)
{
	GameManager::getInstance()->removeGameObject(gameObject);
}