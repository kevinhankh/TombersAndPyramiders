#include "NetworkedGameScene.h"
#include "GLHeaders.h"
#include "SpriteRendererManager.h"
#include "Shader.h"
#include "SharedConstants.h"
#include "SceneTemplate.h"
#include <iostream>
#include "Camera.h"
#include "SpawnManager.h"
#include "CameraFollow.h"
#include "NetworkingManager.h"

NetworkedGameScene::NetworkedGameScene(float hostX, float hostY, float guestX, float guestY)
{
	if (NetworkingManager::getInstance()->isHost())
	{
		SpawnManager::getInstance()->generateNetworkCharacter(guestX, guestY);
		SpawnManager::getInstance()->generatePlayerCharacter(hostX, hostY);
	}
	else {
		SpawnManager::getInstance()->generateNetworkCharacter(hostX, hostY);
		SpawnManager::getInstance()->generatePlayerCharacter(guestX, guestY);
	}
}

void NetworkedGameScene::setCameraFollow(std::shared_ptr<GameObject> toFollow)
{
	Camera::getActiveCamera()->getComponent<CameraFollow>()->setToFollow(toFollow);
}

void NetworkedGameScene::onStart()
{
	Camera::getActiveCamera()->addComponent<CameraFollow>(Camera::getActiveCamera().get());

	for (int x = -10; x < 10; x++)
	{
		for (int y = -10; y < 10; y++)
		{
			SpawnManager::getInstance()->generateMiscSquare(x * 2, y * 2, 2);
		}
	}
}

void NetworkedGameScene::onPause()
{

}

void NetworkedGameScene::onEnd()
{

}

void NetworkedGameScene::onUpdate(int ticks)
{
}