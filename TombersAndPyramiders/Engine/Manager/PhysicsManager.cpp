
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
					if (checkCollision(c1->getTransform(), c2->getTransform()) < (c1->getRadius() - 0.2f + c2->getRadius()))
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

float PhysicsManager::checkCollision(Transform* obj1, Transform* obj2)
{
	return sqrt(pow(obj1->getX() - obj2->getX(), 2) + pow(obj1->getY() - obj2->getY(), 2));
}

void PhysicsManager::purge()
{
	m_sceneColliders.clear();
}