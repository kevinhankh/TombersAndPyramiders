#include "MiscSquare.h"
#include "BoxCollider.h"

MiscSquare::MiscSquare(string spriteName, bool hasCollider) : SimpleSprite(spriteName, 0, 0)
{
	if (hasCollider)
	{
		//addComponent<BoxCollider>(this, getTransform()->getScale(), getTransform()->getScale());
		addComponent<BoxCollider>(this, 1, 1);
	}
}

MiscSquare::~MiscSquare()
{
}