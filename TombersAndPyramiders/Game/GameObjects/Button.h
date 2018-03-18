#pragma once

#include "ComplexSprite.h"
#include "ComponentTemplate.h"
#include "InputManager.h"
#include "AudioManager.h"

#define BUTTON 0
#define BUTTON_HOVER 1

class Button : public ComplexSprite
{
private:
	float m_x, m_y, m_width, m_height;
	string m_type;
public:
	Button(float x, float y, float width, float height, string type);
	~Button();
	std::shared_ptr<ComplexSpriteinfo> generateComplexSpriteInfo(string type);
	void virtual OnClicked();
	bool CheckHovering();

	void onStart() {};
	void onUpdate(int ticks) {

		std::ostringstream message;
		if (CheckHovering())
		{
			message << "True" << endl;
			changeSprite(BUTTON_HOVER);
		}
		else
		{
			message << "False" << endl;
			changeSprite(BUTTON);
			AudioManager::getInstance()->playIgniteSFX();
		}
		OutputDebugString(message.str().c_str());

		if (CheckHovering() && (GetKeyState(VK_LBUTTON) & 0x80) != 0)
		{
			// Do something when clicked
			OnClicked();
		}
	};
	void onEnd() {};

};