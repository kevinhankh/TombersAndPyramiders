#pragma once

#include "BasePossessableController.h"

class ObstacleController : public BasePossessableController
{
public:
	ObstacleController(GameObject* parentGameobject, BasePilot* pilot);
	void onPossessionStart();
	void onPossessionEnd();
	void move(Vector2 direction);
	void trigger();
};