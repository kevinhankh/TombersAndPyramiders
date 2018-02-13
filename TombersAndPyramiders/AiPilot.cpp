#pragma

#include "AiPilot.h"
#include "CharacterController.h"
#include "Vector2.h"

			
void AiPilot::WalkRandomly()
{
}

void AiPilot::Attackable()
{
}

void AiPilot::setController(BaseController* controller)
{
	BasePilot::setController(controller);

	
	m_characterController = static_cast<CharacterController*>(controller);
}


void AiPilot::onStart()
{
	currentState = walk;
}

void AiPilot::onUpdate(int ticks)
{


	switch (currentState)
	{
	case walk:
		WalkRandomly();
		break;
	case attack:
		Attackable();
		break;
	}

	if (m_characterController != nullptr)
	{
		m_characterController->move(getMovement());
	}
}

void AiPilot::onEnd()
{}

Vector2 AiPilot::getMovement()
{
	Vector2 movement = Vector2(0, 0);
	
	movement.setX(-1.0f);

	return movement;
}