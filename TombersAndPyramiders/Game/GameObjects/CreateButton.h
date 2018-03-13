#pragma once

#include "SimpleSprite.h"
#include "ComponentTemplate.h"
#include "Button.h"

class CreateButton : public Button
{
private:

public:
	CreateButton(string text, string spriteName, float x, float y, float z, float scale);
	~CreateButton();
	void OnClicked();

	void onStart() {};
	void onUpdate(int ticks) {};
	void onEnd() {};

};