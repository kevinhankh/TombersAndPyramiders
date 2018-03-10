#pragma once

#include "BaseController.h"

extern class Vector2;
extern class BasePilot;

extern class GhostCharacter;

class GhostController : public BaseController
{
private:
	Vector2 m_movementSpeed;
public:
	GhostController(GameObject* parentGameobject, BasePilot* pilot = nullptr);

	void onUpdate(int ticks);
	void onStart();
	void move(Vector2 moveInput);
};
