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
#include <memory>
#include <WoodenLongbow.h>
#include "AudioManager.h"

std::shared_ptr<Character> player = nullptr;

CharacterTestScene::CharacterTestScene()
{
}

void CharacterTestScene::onStart()
{
	AudioManager::getInstance()->playMusic();
	Camera::getActiveCamera()->addComponent<CameraFollow>(Camera::getActiveCamera().get());

	const int size = 10;
	const int scale = 5;

	for (int x = -size; x < size; x++)
	{
		for (int y = -size; y < size; y++)
		{
			SpawnManager::getInstance()->generateMiscSquare(x * scale, y * scale, scale);
		}
	}


	player = SpawnManager::getInstance()->generatePlayerCharacter(15, 5);

	SpawnManager::getInstance()->generateWorldItem(-5, -5, std::make_shared<WoodenLongbow>());

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