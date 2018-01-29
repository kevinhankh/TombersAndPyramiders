#pragma once

#include <vector>
#include "GameObject.h"
#include "Transform.h"
#include "Collider.h"

class PhysicsManager : public Updateable 
{
private:
	static PhysicsManager* s_instance;
	std::map<int, GameObject*> m_sceneObjects;
	std::vector<Collider*> m_sceneColliders;
	float checkCollision(Transform* obj1, Transform* obj2);
public:
	static PhysicsManager* getInstance();
	void onUpdate(int ticks);
	void onStart();
	void onEnd();
	void addCollider(Collider* c);
	void removeCollider(Collider* c);
	void purge();
};