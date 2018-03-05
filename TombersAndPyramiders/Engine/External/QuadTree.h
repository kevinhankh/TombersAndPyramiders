#pragma once

#include <vector>
#include <memory>
#include "GameObject.h"
#include <set>

struct QuadTreeBounds
{
private:
	float m_x;
	float m_y;
	float m_width;
	float m_height;
public:
	QuadTreeBounds(float x, float y, float width, float height);
	QuadTreeBounds(std::shared_ptr<GameObject> gameObject);
	float getX();
	float getY();
	float getWidth();
	float getHeight();
};

class QuadTree
{
private:
	static const int m_maxItems = 10; //maximum number of Items a node can hold until splitting
	static const int m_maxDepth = 4; //maximum depth of the quadTree

	//bounding box intersection
	static bool intersects(QuadTreeBounds &quadBounds1, QuadTreeBounds &quadBounds2);

	//Node constituting tree structure
	struct Node
	{
	public:
		QuadTreeBounds m_bounds; //physical bounds of node
		const int m_depth; //depth

		std::unique_ptr<Node> m_children[4]; //child nodes
		std::vector<std::shared_ptr<GameObject>> m_items; //collection of retItems

		Node(QuadTreeBounds &_bounds, int pLevel);

		bool isLeaf();
		void split();
		void populate(QuadTreeBounds& bounds, std::vector<std::shared_ptr<GameObject>> &retItems);
		void insert(std::shared_ptr<GameObject> item);
		void reconstruct(std::vector<std::shared_ptr<GameObject>> &gameObjects, int& deletions);
		void getAll(std::set<std::shared_ptr<GameObject>> &gameObjects);
	};

	Node m_root;
	std::vector<std::shared_ptr<GameObject>> m_lazyInserts;

public:
	QuadTree(QuadTreeBounds quadRect);
	void insert(std::shared_ptr<GameObject> gameObject);
	void lazyInsert(std::shared_ptr<GameObject> gameObject);
	void populateList(QuadTreeBounds & bounds, std::vector<std::shared_ptr<GameObject>> &gameObjects);
	int reconstruct();
	QuadTreeBounds getBounds();
	std::set<std::shared_ptr<GameObject>> getAll();

};