#include "QuadTree.h"
#include <iostream>
#include <sstream>

QuadTreeBounds::QuadTreeBounds(float x, float y, float width, float height)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
}


QuadTreeBounds::QuadTreeBounds(std::shared_ptr<GameObject> gameObject)
{
	if (gameObject != nullptr)
	{
		m_x = gameObject->getTransform()->getX();
		m_y = gameObject->getTransform()->getY();
		m_width = gameObject->getTransform()->getScale();
		m_height = gameObject->getTransform()->getScale();
	}
	else
	{
		throw "ERROR::QuadTreeBounds(std::shared_ptr<GameObject> gameObject)::GameObject given was nullptr";
	}
}

float QuadTreeBounds::getX() { return m_x; }
float QuadTreeBounds::getY() { return m_y; }
float QuadTreeBounds::getWidth() { return m_width; }
float QuadTreeBounds::getHeight() { return m_height; }

bool QuadTree::intersects(QuadTreeBounds &quadBounds1, QuadTreeBounds &quadBounds2)
{
	return !(
		quadBounds1.getX() + quadBounds1.getWidth() / 2.0f < quadBounds2.getX() - quadBounds2.getWidth() / 2.0f ||
		quadBounds1.getX() - quadBounds1.getWidth() / 2.0f > quadBounds2.getX() + quadBounds2.getWidth() / 2.0f ||
		quadBounds1.getY() - quadBounds1.getHeight() / 2.0f > quadBounds2.getY() + quadBounds2.getHeight() / 2.0f ||
		quadBounds1.getY() + quadBounds1.getWidth() / 2.0f < quadBounds2.getY() - quadBounds2.getHeight() / 2.0f
		);
}

QuadTree::Node::Node(QuadTreeBounds &_bounds, int pLevel) : m_bounds(_bounds), m_depth(++pLevel)
{

}

bool QuadTree::Node::isLeaf()
{
	return m_children[0] == nullptr;
}

void QuadTree::Node::split()
{
	//create a child for each quadrant
	float newWidth = m_bounds.getWidth() / 2.0f;
	float newHeight = m_bounds.getHeight() / 2.0f;

	//TopLeft: 100-50, 100+50, 100, 100
	m_children[0].reset(new Node(QuadTreeBounds(m_bounds.getX() - newWidth / 2.0f, m_bounds.getY() + newHeight / 2.0f, newWidth, newHeight), m_depth));  //TopLeft
	//TopRight: 100+50, 100+50
	m_children[1].reset(new Node(QuadTreeBounds(m_bounds.getX() + newWidth / 2.0f, m_bounds.getY() + newHeight / 2.0f, newWidth, newHeight), m_depth)); //TopRight
	//BottomLeft: 100-50, 100-50
	m_children[2].reset(new Node(QuadTreeBounds(m_bounds.getX() - newWidth / 2.0f, m_bounds.getY() - newHeight / 2.0f, newWidth, newHeight), m_depth)); //BottomLeft
	//BottomRight: 100+50, 100-50
	m_children[3].reset(new Node(QuadTreeBounds(m_bounds.getX() + newWidth / 2.0f, m_bounds.getY() - newHeight / 2.0f, newWidth, newHeight), m_depth)); //BottomRight
	//insert items into children

	for (int j = 0; j < m_items.size(); j++)
	{
		std::shared_ptr<GameObject> object = m_items[j];
		for (int i = 0; i < 4; i++)
		{
			if (object != nullptr)
			{
				m_children[i]->insert(object);
			}
		}
	}

	//clear item collection
	m_items.clear();
}

void QuadTree::Node::populate(QuadTreeBounds& bounds, std::vector<std::shared_ptr<GameObject>> &retItems)
{
	if (!intersects(m_bounds, bounds))
	{
		return; //item isn’t in bounds, don’t perform population
	}

	if (isLeaf())
	{
		for (int i = 0; i < m_items.size(); i++)
		{
			if (m_items[i] != nullptr)
			{
				retItems.push_back(m_items[i]);
			}
			
		}
		//retItems.insert(retItems.end(), m_items.begin(), m_items.end()); //leaf node, populate return collection
	}
	else
	{
		for (auto &child : m_children)
		{
			child->populate(bounds, retItems); //attempt to populate from children
		}
	}
}

void QuadTree::Node::insert(std::shared_ptr<GameObject> item)
{
	if (!intersects(m_bounds, QuadTreeBounds(item)))
	{
		return; //item isn’t in bounds, don’t perform insertion
	}

	if (isLeaf() && m_items.size() == m_maxItems && m_depth < m_maxDepth)
	{
		split(); //criteria met for split, perform operation
	}

	if (isLeaf())
	{
		m_items.push_back(item); //leaf node, directly add to item collection. If items is bigger than max size before split, it'll keep growing since we're at max depth
	}
	else
	{
		for (auto &child : m_children)
		{
			child->insert(item); //attempt to insert into children
		}
	}
}

void QuadTree::Node::reconstruct(std::vector<std::shared_ptr<GameObject>> &gameObjects)
{
	if (isLeaf())
	{
		for (int i = 0; i < m_items.size(); i++)
		{
			if (m_items[i] != nullptr)
			{
				if (!intersects(m_bounds, QuadTreeBounds(m_items[i])))
				{
					gameObjects.push_back(m_items[i]);
					m_items[i] = nullptr; //Lazy deletion. Will be removed on split, skipped on populate
				}
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++)
		{
			m_children[i]->reconstruct(gameObjects); //attempt to insert into children
		}
	}
}

void QuadTree::lazyInsert(std::shared_ptr<GameObject> gameObject)
{
	m_lazyInserts.push_back(gameObject);
}

void QuadTree::reconstruct()
{
	std::vector<std::shared_ptr<GameObject>> toReinsert;
	m_root.reconstruct(toReinsert);
	for (auto it = toReinsert.begin(); it != toReinsert.end(); it++)
	{
		if (*it != nullptr)
		{
			m_root.insert(*it);
		}
	}
	for (int i = 0; i < m_lazyInserts.size(); i++)
	{
		if (m_lazyInserts[i] != nullptr)
		{
			m_root.insert(m_lazyInserts[i]);
		}
	}
	m_lazyInserts.clear();
}

QuadTree::QuadTree(QuadTreeBounds quadRect) : m_root(quadRect, 0) {}

QuadTreeBounds QuadTree::getBounds()
{
	return m_root.m_bounds;
}

void QuadTree::insert(std::shared_ptr<GameObject> gameObject)
{
	m_root.insert(gameObject);
}

void QuadTree::populateList(QuadTreeBounds & bounds, std::vector<std::shared_ptr<GameObject>> &gameObjects)
{
	m_root.populate(bounds, gameObjects);
}