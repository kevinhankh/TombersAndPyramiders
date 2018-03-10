#pragma once

#include "BasePilot.h"
#include <memory>

extern class BasePossessableController;

class Vector2;

class GhostPilot : public BasePilot
{
private:
	BaseController* m_ghostController;
	std::shared_ptr<BasePossessableController> m_possessableController;
	bool m_possessing;
	
public:
	/** Default constructor. */
	GhostPilot();

public:

public:
	void onStart();

	void onUpdate(int ticks);

	void onEnd();
	void setController(BaseController* controller);

private:
	Vector2 getMovement();
};
