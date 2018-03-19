#pragma once

#include "Scene.h"
#include "GameObject.h"
#include "Shader.h"
#include <memory>
#include "Character.h"
#include "CameraFollow.h"

class CharacterTestScene : public Scene
{
private:


public:
	CharacterTestScene();
	void onStart();
	void onResume() {};
	void onUpdate(int ticks);
	void onPause();
	void onEnd();
	void setCameraFollow(std::shared_ptr<GameObject> toFollow);

	void spawnPlayer(int x, int y);

	std::shared_ptr<Character> player = nullptr;
	std::shared_ptr<Character> Ai = nullptr;

	std::shared_ptr<Character> Ai2 = nullptr;
	std::shared_ptr<Character> Ai3 = nullptr;
	std::shared_ptr<Character> Ai4 = nullptr;
};