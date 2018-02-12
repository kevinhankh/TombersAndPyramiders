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

std::shared_ptr<Character> player = nullptr;

CharacterTestScene::CharacterTestScene()
{
}

void CharacterTestScene::onStart()
{
	Camera::getActiveCamera()->addComponent<CameraFollow>(Camera::getActiveCamera().get());

	// Build floor tiles
	for (int x = -5; x < 5; x++)
	{
		for (int y = 5; y > -5; y--)
		{
			int column = x * 5;
			int row = y * 5;
			SpawnManager::getInstance()->generateMiscSquare(column, row, y - 50, 5);
		}
	}

	//SpawnManager::getInstance()->generateMiscSquare(2.47, 2.15, 0, 5);
	//SpawnManager::getInstance()->generateMiscSquare(-2.47, 2.15, 0, 5);
	//SpawnManager::getInstance()->generateMiscSquare(0, 0, 1, 5);
	//SpawnManager::getInstance()->generateMiscSquare(2.47, -2.15, 2, 5);
	//SpawnManager::getInstance()->generateMiscSquare(-2.47, -2.15, 2, 5);

	player = SpawnManager::getInstance()->generatePlayerCharacter(15, 5);

	setCameraFollow(player);
}

void CharacterTestScene::setCameraFollow(std::shared_ptr<GameObject> toFollow)
{
	Camera::getActiveCamera()->getComponent<CameraFollow>()->setToFollow(toFollow);
}

void CharacterTestScene::onPause()
{
}

void CharacterTestScene::onEnd()
{

}

int counter = 0;
void CharacterTestScene::onUpdate(int ticks)
{
	if (counter++ == 60)
	{
		player->destroy(player);
		player = nullptr;
	}
	if (counter == 120)
	{
		player = SpawnManager::getInstance()->generatePlayerCharacter(-10, 5);
		setCameraFollow(player);
	}
}