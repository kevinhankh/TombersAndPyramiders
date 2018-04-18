#pragma once

#include "BasePilot.h"
#include "TimeInterval.h"
#include <memory>

class ObstaclePilot : public BasePilot
{
private:
	int timePassed = 0;
	std::shared_ptr<TimeInterval> timer;

public:
	ObstaclePilot(std::shared_ptr<TimeInterval> t) {
		timer = t;
	};
	void onStart();
	void onUpdate(int ticks);
	void onEnd() {}
};
