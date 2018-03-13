#pragma once

#include "SimpleSprite.h"
#include "ComponentTemplate.h"

class Button : public SimpleSprite
{
private:
	string m_text;
public:
	Button(string text, string spriteName, float x, float y, float z, float scale);
	~Button();
	void setText(string text);
	string getText();
	void virtual OnClicked();
	void OnHover();
	void OnUnhover();

	void onStart() {};
	void onUpdate(int ticks) {};
	void onEnd() {};

};