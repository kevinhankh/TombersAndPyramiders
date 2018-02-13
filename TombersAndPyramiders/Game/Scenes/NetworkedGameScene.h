#pragma once

#include "Scene.h"
#include "GameObject.h"
#include "Shader.h"
#include "CameraFollow.h"

class NetworkedGameScene : public Scene
{
private:

public:
	NetworkedGameScene();
	void setCameraFollow(std::shared_ptr<GameObject> toFollow);
	void onStart();
	void onResume() {};
	void onUpdate(int ticks);
	void onPause();
	void onEnd();

};