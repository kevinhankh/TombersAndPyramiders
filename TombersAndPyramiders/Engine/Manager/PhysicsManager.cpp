
#include "PhysicsManager.h"
#include <stdio.h>
#include <cmath>
#include "SceneManager.h"
#include <algorithm>

PhysicsManager* PhysicsManager::s_instance;

PhysicsManager* PhysicsManager::getInstance()
{
	if (s_instance == NULL)
		s_instance = new PhysicsManager();
	return s_instance;
}

void PhysicsManager::onStart()
{
	//load gameobjects in scene into vector list
	m_sceneObjects = SceneManager::getInstance()->getCurrentScene()->sceneObjects;
}

void PhysicsManager::onUpdate(int ticks)
{
	//TODO: change to iterators by beta or release
	if (m_sceneColliders.size() > 1)
	{
		for (int i = 0; i < m_sceneColliders.size(); i++)
		{
			m_sceneColliders[i]->clearColliders();
			m_sceneColliders[i]->setCollision(false);
		}
		for (int i = 0; i < m_sceneColliders.size() - 1; i++)
		{
			for (int j = i + 1; j < m_sceneColliders.size(); j++)
			{
				Collider* c1 = m_sceneColliders[i];
				Collider* c2 = m_sceneColliders[j];
				if (!c1->getDisabled() && !c2->getDisabled())
				{
					if (checkCollision(c1, c2))
					{
						c1->getTransform()->getY();
						c1->addCollision(c2->getGameObject());
						c1->setCollision(true);
						c2->setCollision(true);
						c2->addCollision(c1->getGameObject());
					}
				}
			}
		}
	}
}

void PhysicsManager::addCollider(Collider* c)
{
	m_sceneColliders.push_back(c);
}

void PhysicsManager::removeCollider(Collider* c)
{
	m_sceneColliders.erase(std::remove(m_sceneColliders.begin(), m_sceneColliders.end(), c), m_sceneColliders.end());
}

void PhysicsManager::onEnd()
{

}

bool PhysicsManager::checkCollision(Collider* c1, Collider* c2)
{
	// Determine the type of collision (i.e. circle->circle, circle->box, box->box)
	CircleCollider *circleCollider1 = dynamic_cast<CircleCollider*>(c1);
	CircleCollider *circleCollider2 = dynamic_cast<CircleCollider*>(c2);
	BoxCollider *boxCollider1 = dynamic_cast<BoxCollider*>(c1);
	BoxCollider *boxCollider2 = dynamic_cast<BoxCollider*>(c2);

	if (circleCollider1 != NULL && circleCollider2 != NULL) // Circle on Circle Collision
	{
		return checkCircleCollision(circleCollider1, circleCollider2);
	}

	else if (boxCollider1 != NULL & boxCollider2 != NULL) // Box on Box Collision
	{
		return checkBoxCollision(boxCollider1, boxCollider2);
	}
	else if (circleCollider1 != NULL && boxCollider2 != NULL) // Circle on Box Collision
	{
		return checkCircleBoxCollision(circleCollider1, boxCollider2);
	}
	else if (circleCollider2 != NULL && boxCollider1 != NULL) // Box on Circle Collision
	{
		return checkCircleBoxCollision(circleCollider2, boxCollider1);
	}
	return false; // We can't determine if there was a collision
}

bool PhysicsManager::checkCircleCollision(CircleCollider* c1, CircleCollider* c2)
{
	float radiusDistance = sqrt(pow(c1->getTransform()->getX() - c2->getTransform()->getX(), 2) + pow(c1->getTransform()->getY() - c2->getTransform()->getY(), 2));

	return radiusDistance < (c1->getRadius() - 0.2f + c2->getRadius());
}

bool PhysicsManager::checkBoxCollision(BoxCollider* c1, BoxCollider* c2)
{
	// check if there is a collision between a box and a box

	return false;
}

bool PhysicsManager::checkCircleBoxCollision(CircleCollider* c, BoxCollider* b)
{
	// check if there is a collision between a circle and a box

	return false;
}

void PhysicsManager::purge()
{
	m_sceneColliders.clear();
}