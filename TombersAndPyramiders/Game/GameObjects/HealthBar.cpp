#include "HealthBar.h"
#include "MessageManager.h"
#include <sstream>

/*
Message manager callback:


*/

void updateHealthBarCallback(std::map<std::string, void*> data) {
	HealthBar* healthBar = (HealthBar*)data["this"];
	int currentHealth = std::stoi(*(std::string*)data["currentHealth"]);
	int maxHealth = std::stoi(*(std::string*)data["maxHealth"]);
	healthBar->updateHealth(currentHealth, maxHealth);
}


HealthBar::HealthBar() : ComplexSprite(createSpriteInfo(), 0, 0, 1.0f, 2.0f)
{
	m_visible = true;
	m_timeTilDissapear = 3000;
	m_subscriptionID = 0;
}

std::shared_ptr<ComplexSpriteinfo> HealthBar::createSpriteInfo()
{
	auto spriteInfo = std::make_shared<ComplexSpriteinfo>();
	spriteInfo->addInfo("healthBarSheet.png", 10, 1);
	return spriteInfo;
}

void HealthBar::onStart()
{
}

void HealthBar::onUpdate(int ticks)
{
	if (m_timeTilDissapear >= 0) {
		m_timeTilDissapear -= ticks > 60 ? 60 : ticks;
	}
	else {
		if (getTransform()->getScale() > 0) {
			m_mainSize = getTransform()->getScale();
			getTransform()->setScale(0.0f);
		}
	}
	if (m_playerToTrack != nullptr) {
		getTransform()->setPosition(m_playerToTrack->getTransform()->getX(), m_playerToTrack->getTransform()->getY());
	}
}

HealthBar::~HealthBar()
{
}

void HealthBar::setTrackingPlayer(std::shared_ptr<GameObject> playerToTrack)
{
	if (m_subscriptionID != 0) {
		std::stringstream oldEvent;
		oldEvent << m_playerToTrack->getId() << "|HURT";
		MessageManager::unSubscribe(oldEvent.str(), m_subscriptionID);
	}
	m_playerToTrack = playerToTrack;
	std::stringstream newEvent;
	newEvent << m_playerToTrack->getId() << "|HURT";
	m_subscriptionID = MessageManager::subscribe(newEvent.str(), updateHealthBarCallback, this);
}

void HealthBar::updateHealth(float currentHealth, float maxHealth) {
	float percent = currentHealth / maxHealth * 100;
	int spriteIndex = 0;
	//setCurrentSpriteIndex(0) is full, setCurrentSpriteIndex(9) is 0% health. hmm
	int toCheck = 90;
	for (int toCheck = 90; toCheck >= 0; toCheck -= 10) { //toCheck >= 0 or 10?
		if (percent < toCheck) {
			spriteIndex++;
		}
	}
	setCurrentSpriteIndex(spriteIndex);
	getTransform()->setScale(m_mainSize);
	m_timeTilDissapear = 300;
}