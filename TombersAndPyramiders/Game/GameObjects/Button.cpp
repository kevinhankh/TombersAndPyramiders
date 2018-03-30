#include "Button.h"
#include <string>
#include "SpriteRendererManager.h"
#include "SDL.h"
#include "SDL_syswm.h"
#include "NetworkingManager.h"
#include "SpawnManager.h"

Button::Button(float x, float y, float z, float width, float height, string type) : ComplexSprite(generateComplexSpriteInfo(type), x / 25, y / 25, z, 10)
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_width = width;
	m_height = height;
	m_type = type;
	if (type == "Info")
		m_controlPanel = dynamic_pointer_cast<Panel>(GameManager::getInstance()->createGameObject<Panel>(false, 0, 0, 512, 384, "Controls"));
	m_soundEffect = addComponent<AudioSource>(this);
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
	else if (m_type == "Info") { }
	else if (m_type == "Exit")
		exit(0);
}

void Button::OnHover()
{
	m_soundEffect->playSFX(SFX_BUTTON_HOVER);
}

bool Button::CheckHovering()
{
	auto mousePosition = InputManager::getInstance()->getMousePosition();
	mousePosition->setX(mousePosition->getX() - SCREEN_WIDTH / 2);
	mousePosition->setY(-mousePosition->getY() + SCREEN_HEIGHT / 2);
	return	mousePosition->getX() >= m_x - m_width / 2 &&
		mousePosition->getX() <= m_x + m_width / 2 &&
		mousePosition->getY() >= m_y - m_height / 2 &&
		mousePosition->getY() <= m_y + m_height / 2;
}
