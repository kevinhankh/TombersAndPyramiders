#pragma once

#include "ComplexSprite.h"
#include "ComponentTemplate.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "SpawnManager.h"
#include "GameManager.h"
#include "Panel.h"

#define BUTTON 0
#define BUTTON_HOVER 1

class Button : public ComplexSprite
{
private:
	float m_x, m_y, m_width, m_height;
	string m_type;
	std::shared_ptr<Panel> m_controlPanel;
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
			if (m_type == "Info")
			{
				m_controlPanel->setVisible(true);
			}
		}
		else
		{
			message << "False" << endl;
			changeSprite(BUTTON);
			//AudioManager::getInstance()->playIgniteSFX();
			if (m_type == "Info")
			{
				m_controlPanel->setVisible(false);
			}
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