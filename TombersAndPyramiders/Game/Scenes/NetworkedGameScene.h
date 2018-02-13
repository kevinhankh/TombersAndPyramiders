#pragma once

#include "Scene.h"
#include "GameObject.h"
#include "Shader.h"
#include "CameraFollow.h"

class NetworkedGameScene : public Scene
{
private:

public:
	NetworkedGameScene(float hostX, float hostY, Uint32 guestIP, float guestX, float guestY);
	void setCameraFollow(std::shared_ptr<GameObject> toFollow);
	void onStart();
	void onResume() {};
	void onUpdate(int ticks);
	void onPause();
	void onEnd();

};