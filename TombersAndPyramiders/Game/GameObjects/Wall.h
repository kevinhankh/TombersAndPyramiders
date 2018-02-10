#pragma once

#include "SimpleSprite.h"
#include "ComponentTemplate.h"
#include "BoxCollider.h"

//Instance/Wall
class Wall : public SimpleSprite
{
private:
	////Private Variables
	BoxCollider* m_boxCollider = nullptr;

	////Private Methods

public:
	////Public Variables

	////Public Methods
	//The constructor that is called on creation
	Wall();
	//The destructor that is called on deletion
	~Wall();

	void onStart() {};
	void onUpdate(int ticks);
	void onEnd() {};

};