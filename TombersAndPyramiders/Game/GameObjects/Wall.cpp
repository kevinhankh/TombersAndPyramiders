#include "Wall.h"
#include "InputManager.h"
#include "BoxCollider.h"
#include "SpriteRenderer.h"

/*
Constructor called when the GameObject is created. Any GameObject specific creation code can go here.
This includes adding relevant components or any setup.

By default, GameObject's base class has a Transform component
*/
Wall::Wall() : SimpleSprite("WallHorizontal.png", 0, 0)
{
	//Adding a base component. You create the new Component, pass it 'this', cast to a Component* then add it
	addComponent<ComponentTemplate*>(new ComponentTemplate(this));
	m_boxCollider = new BoxCollider(this, 10, 2);
	addComponent<BoxCollider*>(m_boxCollider);
}

Wall::~Wall()
{
}

void Wall::onUpdate(int ticks) {


	/*if (m_boxCollider != nullptr && m_boxCollider->collisionDetected()) {

	}
	else {
		this->getTransform()->addX(0.15f);
	}*/
}