#pragma once

#include "GeneratorManager.h"
#include <vector>
#include "GameManager.h"

GeneratorManager* GeneratorManager::s_instance;

GeneratorManager* GeneratorManager::getInstance()
{
	if (s_instance == NULL)
		s_instance = new GeneratorManager();
	return s_instance;
}

/*std::shared_ptr<GeneratorManager> GeneratorManager::s_instance;

std::shared_ptr<GeneratorManager> GeneratorManager::getInstance()
{
	if (s_instance == nullptr)
		s_instance = GameManager::getInstance()->createGameObject<GeneratorManager>(true);
	return s_instance;
}*/

GeneratorManager::GeneratorManager()
{

}

void GeneratorManager::generateLevel(int width, int height, int detailLevel) 
{
	m_worldTree = std::make_shared<BinaryTree>(width, height);
	m_worldTree->partition(detailLevel);
	m_worldTree->makeRooms();
}