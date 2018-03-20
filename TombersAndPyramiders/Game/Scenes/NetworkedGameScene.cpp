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
#include <memory>
#include "WoodenShortsword.h"
#include "GeneratorManager.h"
#include "GameManager.h"

std::map<int, shared_ptr<Character>> players;
std::shared_ptr<Character> Ai = nullptr;
std::shared_ptr<Character> Ai2 = nullptr;
std::shared_ptr<Character> Ai3 = nullptr;
std::shared_ptr<Character> Ai4 = nullptr;

NetworkedGameScene::NetworkedGameScene ()
{

}

void NetworkedGameScene::onStart ()
{
	GameManager::getInstance()->resizeQuadTree(0, 0, 200, 200);

	SpawnManager::getInstance()->generateMiscSquare(25, -25, -100, 200, "sandBG.png", false);
	SpawnManager::getInstance()->generateWorldItem(5, -5, std::make_shared<WoodenShortsword>());

	//Ai = SpawnManager::getInstance ()->generateAiCharacter (14, -15);
	//Ai2 = SpawnManager::getInstance ()->generateAiCharacter (44, -20);
	//Ai3 = SpawnManager::getInstance ()->generateAiCharacter (54, -40);
	//Ai4 = SpawnManager::getInstance ()->generateAiCharacter (14, -35);

	Camera::getActiveCamera ()->addComponent<CameraFollow> (Camera::getActiveCamera ().get ());
	AudioManager::getInstance ()->playMusic (MUSIC_LEVEL_1);
}

void NetworkedGameScene::onPause ()
{

}

void NetworkedGameScene::onEnd ()
{

}

void NetworkedGameScene::onUpdate (int ticks)
{
}