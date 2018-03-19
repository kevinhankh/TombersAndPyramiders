#include "Room.h"
#include "SpawnManager.h"

Room::Room(int width, int height, int xPosition, int yPosition, bool exit) : m_width(width), m_height(height), m_xCoord(xPosition), m_yCoord(yPosition), m_exit(exit),
		ComplexSprite(generateComplexSpriteInfo(), 0, -2, 10, 5)
{
	m_scale = 5;
}

void Room::draw() 
{
	std::cout << m_xCoord << " " << m_yCoord << std::endl;
	std::cout << m_width << " " << m_height << std::endl;
	//algorithm for drawing a room 
	//SpawnManager::getInstance()->generateMiscSquare(m_xCoord+2, m_yCoord-2, 10, m_scale, "stoneTile.png", true);

	for (int i = 0; i < m_height; i++) 
	{
		for (int j = 0; j < m_width; j++) 
		{
			if (i == 0 && j == 0) 
			{
				// top left corner
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -1, m_scale, "wallTopLeft.png", false);
			}
			else if (i == 0 && j == m_width - 1)
			{
				//top right corner
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -1, m_scale, "wallTopRight.png", false);
			}
			else if (i == m_height - 1 && j == 0)
			{
				//bottom left corner
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -1, m_scale, "wallBottomLeft.png", false);
			}
			else if (i == m_height - 1 && j == m_width - 1)
			{
				//bottom right corner
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -1, m_scale, "wallBottomRight.png", false);
			}
			else if (i == 0) 
			{
				//top wall
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -1, m_scale, "wallTop.png", false);
			}
			else if (j == 0)
			{
				//left wall
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -1, m_scale, "wallLeft.png", false);
			}
			else if (i == m_height - 1)
			{
				//bottom wall
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -1, m_scale, "wallBottom.png", false);
			}
			else if (j == m_width - 1)
			{
				//right wall
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -1, m_scale, "wallRight.png", false);
			}
			else 
			{
				//floor
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -1, m_scale, "stoneTile.png", false);
			}
			
		}
	}
	if (m_exit) {
		//draw stairs
		int x = rand() % m_width/2 + m_width/4;
		int y = rand() % m_height/2 + m_width/4;
		SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + x * 5, m_yCoord * 5 - 2 - y * 5, 0, m_scale, "tower.png", false);

	}
}

std::shared_ptr<ComplexSpriteinfo> Room::generateComplexSpriteInfo()
{
	std::shared_ptr<ComplexSpriteinfo> spriteInfo = std::make_shared<ComplexSpriteinfo>();

	spriteInfo->addInfo("stoneTile.png", 1, 1);

	return spriteInfo;
}