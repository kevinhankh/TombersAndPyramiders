#pragma once
#include "BasePossessableController.h"

class TowerController : public BasePossessableController {
public:
	virtual void onPossessionStart(BasePilot* pilot);
	virtual void onPossessionEnd();
	virtual void trigger();
};