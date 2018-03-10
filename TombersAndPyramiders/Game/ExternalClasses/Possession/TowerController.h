#pragma once
#include "BasePossessableController.h"

class TowerController : public BasePossessableController {
public:
	TowerController(GameObject* parentGameobject, BasePilot* pilot);
	virtual void onPossessionStart();
	virtual void onPossessionEnd();
	virtual void trigger();
};