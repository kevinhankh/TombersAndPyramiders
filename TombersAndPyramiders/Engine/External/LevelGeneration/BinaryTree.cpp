
#include "BinaryTree.h"
#include <time.h>
#include <math.h>

BinaryTree::BinaryTree(int width, int height)
{
	m_root = std::make_shared<BTNode>(width, height, -width/2, height/2);
}

void BinaryTree::partition(int depth)
{
	partition(depth, m_root);
}

void BinaryTree::makeRooms()
{
	makeRooms(m_root);
}

void BinaryTree::makeRooms(std::shared_ptr<BTNode> node) {

}

void BinaryTree::partition(int depth, std::shared_ptr<BTNode> node)
{
	//TODO: fix bug that crashes with very small area size and large depth
	srand(time(NULL));
	if (depth == 0)
	{
		// make room
		//70%-90% of box
		int roomHeight = rand() % (int)ceil((0.2f * node->m_boundsHeight)) + (int)ceil((0.7f * node->m_boundsHeight));
		int roomWidth = rand() % (int)ceil((0.2f * node->m_boundsWidth)) + (int)ceil((0.7f * node->m_boundsWidth));
		int yOffset = rand() % (node->m_boundsHeight - roomHeight);
		int xOffset = rand() % (node->m_boundsWidth - roomWidth);
		return;
	}

	if (node != nullptr)
	{
		//choose random direction
		int direction = rand() % 2;
		
		//choose random position x for vertical, y for horizontal
		if (direction == 1)
		{ //horizontal split
			
			int position = rand() % (int)ceil((0.6f * node->m_boundsHeight)) + (int)ceil((0.2f * node->m_boundsHeight));
			node->left = std::make_shared<BTNode>(node->m_boundsWidth, position, node->m_cornerX, node->m_cornerY);
			node->right = std::make_shared<BTNode>(node->m_boundsWidth, node->m_boundsHeight - position, node->m_cornerX, node->m_cornerY + position);
			partition(depth - 1, node->left);
			partition(depth - 1, node->right);
		}
		else if (direction == 0)
		{ //vertical split
			int position = rand() % (int)ceil((0.6f * node->m_boundsWidth)) + (int)ceil((0.2f * node->m_boundsWidth));
			node->left = std::make_shared<BTNode>(position, node->m_boundsHeight, node->m_cornerX, node->m_cornerY);
			node->right = std::make_shared<BTNode>(node->m_boundsWidth - position, node->m_boundsHeight, node->m_cornerX + position, node->m_cornerY);
			partition(depth - 1, node->left);
			partition(depth - 1, node->right);
		}
	}
}


BinaryTree::BTNode::BTNode(int width, int height, int cornerX, int cornerY) : m_boundsWidth(width), m_boundsHeight(height), m_cornerX(cornerX), m_cornerY(cornerY)
{

}