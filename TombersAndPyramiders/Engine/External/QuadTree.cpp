#include "QuadTree.h"


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
		quadBounds1.getX() + quadBounds1.getWidth() < quadBounds2.getX() ||
		quadBounds1.getX() > quadBounds2.getX() + quadBounds2.getWidth() ||
		quadBounds1.getY() > quadBounds2.getY() + quadBounds2.getHeight() ||
		quadBounds1.getY() + quadBounds1.getWidth() < quadBounds2.getY()
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
	m_children[0].reset(new Node(QuadTreeBounds(m_bounds.getX(), m_bounds.getY(), newWidth, newHeight), m_depth));
	m_children[1].reset(new Node(QuadTreeBounds(m_bounds.getX() + newWidth, m_bounds.getY(), newWidth, newHeight), m_depth));
	m_children[2].reset(new Node(QuadTreeBounds(m_bounds.getX(), m_bounds.getY() + newHeight, newWidth, newHeight), m_depth));
	m_children[3].reset(new Node(QuadTreeBounds(m_bounds.getX() + newWidth, m_bounds.getY() + newHeight, newWidth, newHeight), m_depth));
	//insert items into children
	for (int j = 0; j < m_items.size(); j++)
	{
		std::shared_ptr<GameObject> object = m_items[j];
		for (int i = 0; i < 4; i++)
		{
			m_children[i]->insert(object);
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
		retItems.insert(retItems.end(), m_items.begin(), m_items.end()); //leaf node, populate return collection
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
		m_items.push_back(item); //leaf node, directly add to item collection
	}
	else
	{
		for (auto &child : m_children)
		{
			child->insert(item); //attempt to insert into children
		}
	}
}

QuadTree::QuadTree(QuadTreeBounds quadRect) : m_root(quadRect, 0) {}

void QuadTree::insert(std::shared_ptr<GameObject> gameObject)
{
	m_root.insert(gameObject);
}

void QuadTree::populateList(QuadTreeBounds & bounds, std::vector<std::shared_ptr<GameObject>> &gameObjects)
{
	m_root.populate(bounds, gameObjects);
}