#include "CharacterTestScene.h"
#include "GLHeaders.h"
#include "SpriteRendererManager.h"
#include "Shader.h"
#include "SharedConstants.h"
#include <iostream>
#include "Camera.h"
#include "MovingSquare.h"
#include "MiscSquare.h"
#include <vector>
#include "SpawnManager.h"
#include "InputManager.h"
#include "NetworkingManager.h"
#include "SceneManager.h"
#include "MessageManager.h"
#include "NetworkedGameScene.h"

std::shared_ptr<Character> player = nullptr;

CharacterTestScene::CharacterTestScene ()
{
}

void CharacterTestScene::onStart ()
{
	Camera::getActiveCamera ()->addComponent<CameraFollow> (Camera::getActiveCamera ().get ());

	for (int x = -5; x < 5; x++)
	{
		for (int y = -5; y < 5; y++)
		{
			SpawnManager::getInstance ()->generateMiscSquare (x * 5, y * 5, 5);
		}
	}
}

void CharacterTestScene::setCameraFollow (std::shared_ptr<GameObject> toFollow)
{
	Camera::getActiveCamera ()->getComponent<CameraFollow> ()->setToFollow (toFollow);
}

void CharacterTestScene::onPause ()
{
}

void CharacterTestScene::onEnd ()
{

}

int counter = 0;
void CharacterTestScene::onUpdate (int ticks)
{

	if (InputManager::getInstance ()->onKeyReleased (SDLK_j))
	{
		NetworkingManager::getInstance ()->createClient ();
		//SpawnManager::getInstance()->generateNetworkCharacter(25, 10);
	}
	if (InputManager::getInstance ()->onKeyReleased (SDLK_h))
	{
		NetworkingManager::getInstance ()->createHost ();
		//SpawnManager::getInstance()->generateNetworkCharacter(25, 10);
	}
	if (InputManager::getInstance ()->onKeyReleased (SDLK_k))
	{
		if (NetworkingManager::getInstance ()->startGame ()) {
			SpawnManager::getInstance ()->sendStartPacket ();
		}
	}
}

void CharacterTestScene::spawnPlayer(int x, int y)
{
	player = SpawnManager::getInstance()->generatePlayerCharacter(x, y);
	setCameraFollow(player);
}


/*


player = SpawnManager::getInstance()->generatePlayerCharacter(15, 5);

setCameraFollow(player);
*/