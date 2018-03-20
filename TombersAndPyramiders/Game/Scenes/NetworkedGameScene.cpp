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
#include "GameManager.h"

std::shared_ptr<Character> player = nullptr;
std::shared_ptr<Character> player2 = nullptr;
std::shared_ptr<Character> Ai = nullptr;
std::shared_ptr<Character> Ai2 = nullptr;
std::shared_ptr<Character> Ai3 = nullptr;
std::shared_ptr<Character> Ai4 = nullptr;

NetworkedGameScene::NetworkedGameScene()
{

}

void NetworkedGameScene::onStart()
{
	GameManager::getInstance()->resizeQuadTree(0, 0, 200, 100);
	SpawnManager::getInstance()->generateMiscSquare(25, -25, -100, 115, "sandBG.png", false);
	AudioManager::getInstance()->playMusic(MUSIC_LEVEL_1);

	const float size = 6;
	const float scale = 5;

	for (float x = 0; x <= size; x++)
	{
		for (float y = 0; y >= -size; y--)
		{
			float column = x * scale;
			float row = y * scale;
			int floorZ = -3;
			int wallZ = -2;
			int stairZ = -1;

			// For setting the floor within the bounds of the map/under the walls
			float floorOffset = 0.5 * scale;

			// Create a staircase
			if (x == 3 && y == -3)
			{
				SpawnManager::getInstance()->generateMiscSquare(column, row, stairZ, scale, "spiralStairs.png", true);
			}

			/*		float floorOffset = 0.56f;
			float wallOffset = 0.0f;*/
			//SpawnManager::getInstance()->generateMiscSquare(column, row - (y * floorOffset), (y * -1) - 50, scale, "stoneTile.png", false);

			if (y == 0)
			{
				// Create top left wall.
				if (x == 0)
				{
					SpawnManager::getInstance()->generateMiscSquare(column, row, wallZ, scale, "wallTopLeft_Edge.png", true);
					SpawnManager::getInstance()->generateMiscSquare(column + floorOffset, row - floorOffset, floorZ - 1, scale, "stoneTile_Edge.png", false);
				}
				// Create top right wall.
				else if (x == size)
				{
					SpawnManager::getInstance()->generateMiscSquare(column, row, wallZ, scale, "wallTopRight_Edge.png", true);
					SpawnManager::getInstance()->generateMiscSquare(column - floorOffset, row - floorOffset, floorZ, scale, "stoneTile_Edge.png", false);
				}
				// Top wall
				else
				{
					SpawnManager::getInstance()->generateMiscSquare(column, row, wallZ, scale, "wallHorizontal.png", true);
					SpawnManager::getInstance()->generateMiscSquare(column, row - floorOffset, floorZ, scale, "stoneTile_Edge.png", false);
				}
			}
			// Create bottom walls.
			else if (y == -size)
			{
				if (x == 0)
				{
					SpawnManager::getInstance()->generateMiscSquare(column, row, wallZ, scale, "wallBottomLeft.png", true);
					SpawnManager::getInstance()->generateMiscSquare(column + floorOffset, row + floorOffset, floorZ, scale, "stoneTile_Edge.png", false);
				}
				else if (x == size)
				{
					SpawnManager::getInstance()->generateMiscSquare(column, row, wallZ, scale, "wallBottomRight.png", true);
					SpawnManager::getInstance()->generateMiscSquare(column - floorOffset, row + floorOffset, floorZ, scale, "stoneTile_Edge.png", false);
				}
				else
				{
					SpawnManager::getInstance()->generateMiscSquare(column, row, wallZ, scale, "wallHorizontal.png", true);
					SpawnManager::getInstance()->generateMiscSquare(column, row + floorOffset, floorZ, scale, "stoneTile_Edge.png", false);
				}
			}
			// Create a left wall
			else if (x == 0)
			{
				SpawnManager::getInstance()->generateMiscSquare(column, row, wallZ, scale, "wallVerticalBothEdge.png", true);
				SpawnManager::getInstance()->generateMiscSquare(column + floorOffset, row, floorZ, scale, "stoneTile_Edge.png", false);
			}
			// Create a right wall.
			else if (x == size)
			{
				float wallHorizontalOffset = 0.0f;

				SpawnManager::getInstance()->generateMiscSquare(column, row, wallZ, scale, "wallVerticalBothEdge.png", true);
				SpawnManager::getInstance()->generateMiscSquare(column - floorOffset, row, floorZ, scale, "stoneTile_Edge.png", false);
			}
			else
			{
				SpawnManager::getInstance()->generateMiscSquare(column, row, floorZ, scale, "stoneTile_Edge.png", false);
			}
		}
	}

	SpawnManager::getInstance()->generateWorldItem(5, -5, std::make_shared<WoodenShortsword>());

	Ai = SpawnManager::getInstance()->generateAiCharacter(14, -15);
	Ai2 = SpawnManager::getInstance()->generateAiCharacter(44, -20);
	Ai3 = SpawnManager::getInstance()->generateAiCharacter(54, -40);
	Ai4 = SpawnManager::getInstance()->generateAiCharacter(14, -35);

	SpawnManager::getInstance()->generateSingleDoor(10, -10, Door::Direction::West, Door::Mode::Closed);

	Camera::getActiveCamera ()->addComponent<CameraFollow> (Camera::getActiveCamera ().get ());	
	if (NetworkingManager::getInstance ()->isHost ())
	{
		setCameraFollow (player);
	}
	else {
		setCameraFollow (player2);
	}
}

void NetworkedGameScene::onPause()
{

}

void NetworkedGameScene::onEnd()
{

}

void NetworkedGameScene::onUpdate(int ticks)
{
}