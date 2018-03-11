#pragma once

#include "BaseController.h"

extern class Vector2;
extern class BasePilot;
extern class GhostCharacter;
extern class BasePossessableController;

class GhostController : public BaseController
{
private:
	Vector2 m_movementSpeed;
	std::shared_ptr<BasePossessableController> m_toFollow;

public:
	GhostController(GameObject* parentGameobject, BasePilot* pilot = nullptr);

	void onUpdate(int ticks);
	void onStart();
	void move(Vector2 moveInput);
	void follow(std::shared_ptr<BasePossessableController> toFollow);
	void possess(std::shared_ptr<BasePossessableController> toPossess);
	void stopPossessing();
};
