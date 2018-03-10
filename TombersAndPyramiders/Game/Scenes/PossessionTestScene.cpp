#include "PossessionTestScene.h"
#include <iostream>
#include <vector>
#include "SpawnManager.h"
#include "Camera.h"
#include "GameManager.h"

std::shared_ptr<GhostCharacter> ghostCharacter;

PossessionTestScene::PossessionTestScene()
{
}

void PossessionTestScene::onStart()
{
	GameManager::getInstance()->resizeQuadTree(0, 0, 200, 100);
	for (int x = -30; x < 31; x += 10) {
		SpawnManager::getInstance()->generateMiscSquare(x, 0, 0, 10, "stoneTile.png", false);
	}
	ghostCharacter = SpawnManager::getInstance()->generateGhost(0, 0);
	SpawnManager::getInstance()->generateTower(5, 0);
	Camera::getActiveCamera()->addComponent<CameraFollow>((GameObject*)Camera::getActiveCamera().get())->setToFollow(ghostCharacter);
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