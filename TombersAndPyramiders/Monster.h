#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector2.h"


class Monster :
	public Component
{
private:

	Transform *myTransform;
	Vector2 *targetPosition;
	void GetTarget();
	Vector2* GetTargetPosition();

	enum State {
		walk = 0,
		shoot = 1,
		dead = 2,
		s_MAX
	}currentState;
	void MoveToTargetBattler(bool isWalking);
	void MoveToTargetPosition(bool isWalking);
	void SetLearnedVelocity();
	void Shoot();

	enum Behaviour {
		none = 0,
		cower = 1,
		engage = 2,
		b_MAX
	}currentBehaviour;
	void GetBehaviour();
	bool CanMakeDecision(float deltaTIme);

	float decisionFrequency;
	float timeSinceLastDecision;
	bool lastActionWasShooting;

	float intelligence;
	float courage;

	bool isLearning;
	int teamID;

public:
	AI(GameObject* gameObject, bool _isLearning);
	~AI();
	void Initialize(float _intelligence, float _courage, float _decisionFrequency);
	void Died();
	void OnStart() {};
	void OnUpdate(int ticks);
	void OnEnd() {};
	void Retarget();

	enum Target {
		battler = 0,
		position = 1,
		t_MAX
	}currentTarget;
	GameObject *targetBattler;
};

