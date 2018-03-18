#include "Button.h"
#include <string>
#include "SpriteRendererManager.h"
#include "SDL.h"
#include "SDL_syswm.h"
#include "NetworkingManager.h"
#include "SpawnManager.h"

Button::Button(float x, float y, float width, float height, string type) : ComplexSprite(generateComplexSpriteInfo(type), x / 25, y / 25, 0, 10)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_type = type;
}

Button::~Button()
{

}

std::shared_ptr<ComplexSpriteinfo> Button::generateComplexSpriteInfo(string type)
{
	std::shared_ptr<ComplexSpriteinfo> spriteInfo = std::make_shared<ComplexSpriteinfo>();

	spriteInfo->addInfo(type + "Button.png", 1, 1);
	spriteInfo->addInfo(type + "ButtonHover.png", 1, 1);

	return spriteInfo;
}

void Button::OnClicked()
{
	if (m_type == "Start")
	{
		if (NetworkingManager::getInstance()->startGame())
			SpawnManager::getInstance()->sendStartPacket();
	}

	else if (m_type == "Host")
		NetworkingManager::getInstance()->createHost();

	else if (m_type == "Join")
		NetworkingManager::getInstance()->createClient();

	else if (m_type == "Options")
		AudioManager::getInstance()->playMusic();

	else if (m_type == "Exit")
		exit(0);
}

bool Button::CheckHovering()
{
	SDL_SysWMinfo systemInfo;
	SDL_VERSION(&systemInfo.version);
	SDL_GetWindowWMInfo(SpriteRendererManager::getInstance()->getWindow(), &systemInfo);

	POINT MousePosition;
	std::ostringstream message;
	if (GetCursorPos(&MousePosition))
	{
		if (ScreenToClient(systemInfo.info.win.window, &MousePosition))
		{
			std::ostringstream message;
			MousePosition.x = MousePosition.x - SCREEN_WIDTH / 2;
			MousePosition.y = -MousePosition.y + SCREEN_HEIGHT / 2;
			message << "x: " << MousePosition.x << " y: " << MousePosition.y << endl;
			OutputDebugString(message.str().c_str());
		}
	}

	return	MousePosition.x >= m_x - m_width / 2 &&
			MousePosition.x <= m_x + m_width / 2 &&
			MousePosition.y >= m_y - m_height / 2 &&
			MousePosition.y <= m_y + m_height / 2;

	/*return	MousePosition.x >= getTransform()->getX() - m_width / 2 &&
			MousePosition.x <= getTransform()->getX() + m_width / 2 &&
			MousePosition.y >= getTransform()->getY() - m_height / 2 &&
			MousePosition.y <= getTransform()->getY() + m_height / 2;*/
}
