#include "ObstaclePilot.h"
#include <cmath>
#include "Randomize.h"
#include "ObstacleController.h"

void ObstaclePilot::onStart()
{

}

void ObstaclePilot::onUpdate(int ticks)
{
	timePassed += ticks;
	if (timer != nullptr && timePassed >= timer->getCurrentTime()) {
		auto ob = dynamic_cast<ObstacleController *>(m_controller);
		ob->trigger();
		timePassed -= timer->getCurrentTime();
		timer->getNextTime(timePassed);
	}
}

