#include "TowerController.h"

TowerController::TowerController(GameObject* parentGameobject, BasePilot* pilot) : BasePossessableController(parentGameobject, pilot) {}

void TowerController::onPossessionStart()
{
	//Could do some visual effect or whatever on fire
}

void TowerController::onPossessionEnd()
{
	//Could do some visual effect or whatever on exit
}

void TowerController::trigger()
{
	std::cout << "FIREEEE" << std::endl;
	//FIREEEEE. Maybe take a trigger direction or something?
}