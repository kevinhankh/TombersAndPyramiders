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

std::shared_ptr<Character> player = nullptr;
std::shared_ptr<Character> player2 = nullptr;

NetworkedGameScene::NetworkedGameScene(float hostX, float hostY, float guestX, float guestY)
{
	if (NetworkingManager::getInstance()->isHost())
	{
		player = SpawnManager::getInstance()->generatePlayerCharacter(hostX, hostY);
		player2 = SpawnManager::getInstance()->generateNetworkCharacter(guestX, guestY);
		setCameraFollow(player);
	}
	else {
		player = SpawnManager::getInstance()->generateNetworkCharacter(hostX, hostY);
		player2 = SpawnManager::getInstance()->generatePlayerCharacter(guestX, guestY);
		setCameraFollow(player2);
	}
}

void NetworkedGameScene::setCameraFollow(std::shared_ptr<GameObject> toFollow)
{
	Camera::getActiveCamera()->getComponent<CameraFollow>()->setToFollow(toFollow);
}

void NetworkedGameScene::onStart()
{
	Camera::getActiveCamera()->addComponent<CameraFollow>(Camera::getActiveCamera().get());

	for (int x = -5; x < 5; x++)
	{
		for (int y = -5; y < 5; y++)
		{
			SpawnManager::getInstance()->generateMiscSquare(x * 5, y * 5, 5);
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