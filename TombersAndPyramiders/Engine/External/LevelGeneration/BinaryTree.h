#pragma once

#include <memory>

class BinaryTree {

public:
	BinaryTree(int width, int height);
	void partition(int depth);
	void makeRooms();
private:
	struct BTNode {
	public:

		int m_cornerY;
		int m_cornerX;
		int m_boundsWidth;
		int m_boundsHeight;
		int m_width;
		int m_height;

		std::shared_ptr<BTNode> left;
		std::shared_ptr<BTNode> right;

		BTNode(int width, int height, int cornerX, int cornerY);
		

	};

	void partition(int depth, std::shared_ptr<BTNode> node);
	void makeRooms(std::shared_ptr<BTNode> node);
	std::shared_ptr<BTNode> m_root;

};