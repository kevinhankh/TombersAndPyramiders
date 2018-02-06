#pragma once

#include <vector>
#include "GameObject.h"
#include "Transform.h"
#include "Collider.h"
#include "CircleCollider.h"
#include "BoxCollider.h"

class PhysicsManager : public Updateable 
{
private:
	static PhysicsManager* s_instance;
	std::map<int, GameObject*> m_sceneObjects;
	std::vector<Collider*> m_sceneColliders;
	bool checkCollision(Collider* c1, Collider* c2);
	bool checkCircleCollision(CircleCollider* c1, CircleCollider* c2);
	bool checkBoxCollision(BoxCollider* c1, BoxCollider* c2);
	bool checkCircleBoxCollision(CircleCollider* c, BoxCollider* b);
public:
	static PhysicsManager* getInstance();
	void onUpdate(int ticks);
	void onStart();
	void onEnd();
	void addCollider(Collider* c);
	void removeCollider(Collider* c);
	void purge();
};