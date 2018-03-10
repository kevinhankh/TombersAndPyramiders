#pragma once
#include "BaseController.h"

extern class GameObject;
extern class BasePilot;

class BasePossessableController : public BaseController {
public:
	BasePossessableController(GameObject* parentGameobject, BasePilot* pilot);
	virtual void onPossessionStart() = 0;
	virtual void onPossessionEnd() = 0;
	virtual void trigger() = 0;
};