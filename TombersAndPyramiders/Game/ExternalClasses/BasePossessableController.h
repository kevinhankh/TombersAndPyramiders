#pragma once
#include "BaseController.h"

class BasePossessableController : public BaseController {
public:
	virtual void onPossessionStart(BasePilot* pilot) = 0;
	virtual void onPossessionEnd() = 0;
	virtual void trigger() = 0;
};