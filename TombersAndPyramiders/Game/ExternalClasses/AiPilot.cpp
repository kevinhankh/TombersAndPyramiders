#pragma
#include "AiPilot.h"
#include "SpawnManager.h"
#include <cmath>
int attackNumber = 0;
int randomNumber = 0;
int attackCount = 0;

void AiPilot::shouldFire()
{
	attackNumber = attackNumber % 6;
	attackCount = attackCount + 1;
	if (attackCount == 120)
	{
		attackNumber = rand();
		attackCount = 0;
	}
	if (attackNumber == 1)
	{
		currentState = attack;
		//attackNumber = rand();
	}

}

void AiPilot::setController(BaseController* controller)
{
	BasePilot::setController(controller);


	m_characterController = static_cast<CharacterController*>(controller);
	//m_characterController1 = static_cast<CharacterController*>(controller);
}


void AiPilot::onStart()
{
	currentState = walk;
	srand(time(NULL));
	//currentState = run;
}

void AiPilot::CheckingTimer()
{
	if (TimePassed >= 1.0f)
	{
		TimePassed = 0.0f;
		for (int i = 0; i < SpawnManager::getInstance()->allPlayers.size(); i++)
		{
			
			float Distance =  SpawnManager::getInstance()->allPlayers[i]->getTransform()->getDistance(m_characterController->getGameObject()->getTransform());
			if (Distance < engageDistance)
			{
				target = SpawnManager::getInstance()->allPlayers[i];
				//playMeleeAttackWeapon();

			}
			else if (Distance > disengageDistance)
			{
				getMovement();
				//playRangeAttackAnimation();
			}
		}
		
	}
}

void AiPilot::onUpdate(int ticks)
{
	TimePassed =  TimePassed + (float)ticks / 1000.0f;
	CheckingTimer();

	switch (currentState)
	{
	case walk:
		if (target == nullptr)
		{
			m_characterController->move(getRandomMovement());
		}
		else
		{
			m_characterController->move(getMovement());
		}
		shouldFire();
		//currentState = run;
		break;
	case attack:
		//m_characterController->useWeapon();
		currentState = walk;
		
		if (target == nullptr)
		{
		//	m_characterController->useWeapon(playMeleeAttackWeapon());
		}
		else
		{
			//m_characterController->useWeapon(playRangeAttackAnimation());
		}
		break;
	
	}


}

void AiPilot::onEnd()
{}

Vector2 AiPilot::getMovement()
{
	if (target != nullptr) {
		float x = abs(target->getTransform()->getX() - m_characterController->getGameObject()->getTransform()->getX()) ;
		float y = abs(target->getTransform()->getY() - m_characterController->getGameObject()->getTransform()->getY()) ;
		x = x + m_characterController->getGameObject()->getTransform()->getX();
		y = y + m_characterController->getGameObject()->getTransform()->getY();
		movement.setX(x);
		movement.setY(y);
	}

	return movement;
}

Vector2 AiPilot::getRandomMovement()
{

	coun++;
	if (coun == 30)
	{
		randomNumber = rand() % 22;
		coun = 0;
	}
	if (randomNumber == 1)
	{
		movement.setX(-0.2f);
	
	}
	else if (randomNumber == 2)
	{
		movement.setX(0.2f);
	
	}
	else if (randomNumber == 3)
	{
		movement.setY(0.2f);
		//movement.setX(0.0f);
	}
	else if (randomNumber == 4 )
	{
		movement.setY(-0.2f);
		//movement.setX(0.0f);
	}
	if (randomNumber == 15 )
	{
		movement.setX(-0.3f);
		movement.setY(0.0f);
	}
	else if (randomNumber == 16)
	{
		movement.setX(0.3f);
		//movement.setY(0.0f);
	}
	else if (randomNumber == 17)
	{
		movement.setY(0.3f);
		movement.setX(0.0f);
	}
	else if (randomNumber == 18)
	{
		movement.setY(-0.3f);
		//movement.setX(0.0f);
	}
		return movement;

}


