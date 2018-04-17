#include "PositionBasedPopup.h"

PositionBasedPopup::PositionBasedPopup(float x, float y, float maxDistance, std::shared_ptr<GameObject> dependant) : SimpleSprite("table.png", x, y)
{
	m_maxDistance = maxDistance;
	m_dependant = dependant;
}

PositionBasedPopup::~PositionBasedPopup()
{

}

void PositionBasedPopup::onStart()
{

}

void PositionBasedPopup::onUpdate(int ticks)
{
	if (m_dependant != nullptr)
	{
		if (getTransform()->getDistance(m_dependant->getTransform()) < m_maxDistance)
		{
			std::cout << "DESTROYED" << std::endl;
			destroy(getId());
		}
	}
	else
	{
		std::cout << "DESTROYED" << std::endl;
		destroy(getId());
	}
}