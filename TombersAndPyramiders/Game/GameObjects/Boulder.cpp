#include "BoxCollider.h"
#include "BoulderController.h"
#include "Boulder.h"
#include "Rigidbody.h"

Boulder::Boulder(BasePilot* pilot) : SimpleSprite("tower.png", 0, 0)
{
	auto boxCollider = addComponent<BoxCollider>(this, 1, 1);
	addComponent<Rigidbody>(this, boxCollider.get());
	addComponentAsParent<BoulderController, BasePossessableController>(this, pilot);
}

Boulder::~Boulder()
{
}