#include "PossessionTestScene.h"
#include <iostream>
#include <vector>
#include "SpawnManager.h"
#include "Camera.h"


PossessionTestScene::PossessionTestScene()
{
}

void PossessionTestScene::onStart()
{
	for (int x = -10; x < 10; x++)
	{
		for (int y = -10; y < 10; y++)
		{
			SpawnManager::getInstance()->generateMiscSquare(x * 5, y * 5, 0, 5, "stoneTile.png", false);
		}
	}
	SpawnManager::getInstance()->generateGhost(0, 0);
	SpawnManager::getInstance()->generateTower(5, 0);
	Camera::getActiveCamera()->addComponent<CameraFollow>((GameObject*)Camera::getActiveCamera().get())->setToFollow(SpawnManager::getInstance()->generateGhost(0, 0));
}

void PossessionTestScene::onPause()
{
}

void PossessionTestScene::onEnd()
{

}

void PossessionTestScene::onUpdate(int ticks)
{
}