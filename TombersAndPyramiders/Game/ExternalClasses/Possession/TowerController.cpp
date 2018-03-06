#include "TowerController.h"

void TowerController::onPossessionStart(BasePilot* pilot)
{
	setPilot(pilot);
	//Could do some visual effect or whatever on fire
}

void TowerController::onPossessionEnd()
{
	setPilot(nullptr);
	//Could do some visual effect or whatever on exit
}

void TowerController::trigger()
{

	//FIREEEEE. Maybe take a trigger direction or something?
}