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
#include "CreateButton.h"

MainMenuScene::MainMenuScene()
{
	
}

void MainMenuScene::onStart()
{
	GameManager::getInstance()->createGameObject<SimpleSprite>(false, "MainMenu.png", 0, 0, -1000, 42);
	GameManager::getInstance()->createGameObject<CreateButton>(false, "Create", "ButtonHover.png", 0, 0, 0, 10);
	GameManager::getInstance()->createGameObject<Button>(false, "button", "Button.png", 0, -3, 0, 10);
	GameManager::getInstance()->createGameObject<Button>(false, "button", "Button.png", 0, -6, 0, 10);
	GameManager::getInstance()->createGameObject<Button>(false, "button", "Button.png", 0, -9, 0, 10);
	GameManager::getInstance()->createGameObject<Button>(false, "button", "Button.png", 0, -12, 0, 10);
}

void MainMenuScene::onPause()
{
}

void MainMenuScene::onEnd()
{
}

void MainMenuScene::onUpdate(int ticks)
{
}