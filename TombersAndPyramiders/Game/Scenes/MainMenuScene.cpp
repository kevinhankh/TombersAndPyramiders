#include "MainMenuScene.h"
#include "GLHeaders.h"
#include "SpriteRendererManager.h"
#include "Shader.h"
#include "SharedConstants.h"
#include "SceneTemplate.h"
#include <iostream>
#include "InputManager.h"
#include "NetworkingManager.h"
#include "SpawnManager.h"
#include "GameManager.h"
#include "AudioManager.h"
#include "Button.h"
#include "Panel.h"

MainMenuScene::MainMenuScene()
{
	
}

void MainMenuScene::onStart()
{
	AudioManager::getInstance()->playMusic();
	GameManager::getInstance()->createGameObject<SimpleSprite>(false, "MainMenu.png", 0, 0, -1000, 42);
	//GameManager::getInstance()->createGameObject<CreateButton>(false, "Create", 100, 100, "ButtonHover.png", 0, 0, 0, 10);
	GameManager::getInstance()->createGameObject<Button>(false, -400, -350, 200, 80, "Start");
	GameManager::getInstance()->createGameObject<Button>(false, -200, -350, 200, 80, "Host");
	GameManager::getInstance()->createGameObject<Button>(false, 0, -350, 200, 80, "Join");
	GameManager::getInstance()->createGameObject<Button>(false, 200, -350, 200, 80, "Info");
	GameManager::getInstance()->createGameObject<Button>(false, 400, -350, 200, 80, "Exit");
}

void MainMenuScene::onPause()
{
}

void MainMenuScene::onEnd()
{
}

void MainMenuScene::onUpdate(int ticks)
{
	if (InputManager::getInstance()->onKeyReleased(SDLK_j))
	{
		NetworkingManager::getInstance()->createClient();
	}
	if (InputManager::getInstance()->onKeyReleased(SDLK_h))
	{
		NetworkingManager::getInstance()->createHost();
	}
	if (InputManager::getInstance()->onKeyReleased(SDLK_k))
	{
		if (NetworkingManager::getInstance()->startGame()) {
			SpawnManager::getInstance()->sendStartPacket();
		}
	}
	if (InputManager::getInstance()->onKeyReleased(SDLK_q))
	{
		exit(0);
	}
}