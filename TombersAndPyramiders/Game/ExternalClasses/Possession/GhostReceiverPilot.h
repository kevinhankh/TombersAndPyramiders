#pragma once

#include "BasePilot.h"
#include <memory>
#include "Vector2.h"


class GhostReceiverPilot : public BasePilot
{
private:
	Vector2 m_lastNetworkVector;
	int m_updatesUntilInvalid;
	int m_updatesSinceNewMovement;

public:
	/** Default constructor. */
	GhostReceiverPilot();

public:

public:
	void onStart();

	void onUpdate(int ticks);

	void onEnd();
	void setMovement(Vector2 vec, int updates);
};
