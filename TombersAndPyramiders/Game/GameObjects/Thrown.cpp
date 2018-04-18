#include "Thrown.h"
#include "GameManager.h"
#include "SpawnManager.h"
#include "Light.h"
#include "PositionBasedPopup.h"

Thrown::Thrown() : ComplexSprite(createSpriteInfo(), 0, 0)
{
    m_activated = 0;
    m_counter = 0;
    addComponent<Light>(this);
    
}

std::shared_ptr<ComplexSpriteInfo> Thrown::createSpriteInfo()
{
    auto spriteInfo = std::make_shared<ComplexSpriteInfo>();
	spriteInfo->addSprite("thrownIdle.png", "Idle", 1, 1);
    spriteInfo->addAnimation("Idle", "idle", 0, 0);
    spriteInfo->addSprite("thrownActive.png", "Active", 1, 1);
    spriteInfo->addAnimation("Active", "active", 0, 0);
    return spriteInfo;
}

Thrown::~Thrown()
{
    
}

void Thrown::trigger()
{
    changeSpriteSheet("Active");
    m_activated = true;
}

void Thrown::onStart() 
{
    changeSpriteSheet("Idle");
}

void Thrown::onUpdate(int ticks)
{
    auto character = SpawnManager::getInstance()->getActivePlayer();
	if (character != nullptr) 
	{
		auto distance = getTransform()->getDistance(character->getTransform());
		if (distance < 4.0f && !m_popupActive)
		{
			m_popupActive = true;
			GameManager::getInstance()->createGameObject<PositionBasedPopup>(false, getTransform()->getX(), getTransform()->getY(), 4.0f, character, "popupPickup.png");
			//Create Popup to destroy when this & player are 4> distance apart
		}
		else if (distance > 4.0f) {
			m_popupActive = false;
		}
    }
    if (m_activated) {
        m_brightness += sin(m_counter++);
        if (m_brightness < 34) {
            m_brightness += 0.05f;
        }
        getComponent<Light>()->setSize(m_brightness);
    }
}