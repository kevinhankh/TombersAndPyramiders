#pragma once

#include <time.h>
#include "BasePilot.h"
#include "CharacterController.h"
#include "Vector2.h"
#include "Inventory.h"
#include "Character.h"
class CharacterController;
class Vector2;

class AiPilot : public BasePilot
{

private:
	int coun = 0;

	CharacterController* m_characterController;
	//CharacterController* m_characterController1;
	
	Vector2 movement = Vector2(0, 0);

public:
	
	void shouldFire();
	enum state
	{
		walk = 0,
		attack = 1,
		run = 2
	}currentState;

	explicit AiPilot() = default;

public:

	void setController(BaseController* controller);

public:
	void onStart();
	void onUpdate(int ticks);
	void onEnd();
	void CheckingTimer();
	float engageDistance = 10;
	float disengageDistance = 15;
	float TimePassed = 0.0;
	std::shared_ptr<Character> target;
public:
	Vector2 getMovement();
	Vector2 getRandomMovement();
};
