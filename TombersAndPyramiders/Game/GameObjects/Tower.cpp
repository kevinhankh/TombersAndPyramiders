#include "Tower.h"
#include "BoxCollider.h"
#include "TowerController.h"

Tower::Tower() : SimpleSprite("tower.png", 0, 0)
{
	addComponentAsParent<TowerController, BasePossessableController>(this, nullptr);
}

Tower::~Tower()
{
}