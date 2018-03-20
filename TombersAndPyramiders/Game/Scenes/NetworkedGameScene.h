#pragma once

#include "Scene.h"
#include "GameObject.h"
#include "Shader.h"
#include "CameraFollow.h"
#include "Character.h"

class NetworkedGameScene : public Scene
{
private:

public:
<<<<<<< HEAD
	std::vector<time_t> mapSeeds;
=======
>>>>>>> 24577cbfa5a7c4252f61c6a1749a53752988443e
	std::map<Uint32, Character> players;
	NetworkedGameScene();
	void onStart();
	void onResume() {};
	void onUpdate(int ticks);
	void onPause();
	void onEnd();

};