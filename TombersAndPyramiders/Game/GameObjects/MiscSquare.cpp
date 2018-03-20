#include "MiscSquare.h"
#include "BoxCollider.h"

MiscSquare::MiscSquare(string spriteName, bool hasCollider, float colliderSize) : SimpleSprite(spriteName, 0, 0)
{
	if (hasCollider)
	{
		addComponent<BoxCollider>(this, colliderSize, colliderSize);
	}
}

MiscSquare::~MiscSquare()
{
}