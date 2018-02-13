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

std::shared_ptr<Character> player;
std::shared_ptr<Character> player2;

NetworkedGameScene::NetworkedGameScene()
{

}

void NetworkedGameScene::setCameraFollow(std::shared_ptr<GameObject> toFollow)
{
	Camera::getActiveCamera()->getComponent<CameraFollow>()->setToFollow(toFollow);
}

void NetworkedGameScene::onStart()
{
	Camera::getActiveCamera ()->addComponent<CameraFollow> (Camera::getActiveCamera ().get ());	
	if (NetworkingManager::getInstance ()->isHost ())
	{
		setCameraFollow (player);
	}
	else {
		setCameraFollow (player2);
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