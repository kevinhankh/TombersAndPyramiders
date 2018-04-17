#include "WorldItem.h"
#include "SpawnManager.h"
#include "PositionBasedPopup.h"
#include "GameManager.h"

WorldItem::WorldItem(std::shared_ptr<BaseItem> item, float x, float y) : SimpleSprite(item->getItemIcon(), x, y)
{
	m_item = item;
	//Add component: BoxCollider and detect collision
}

std::shared_ptr<BaseItem> WorldItem::pickupItem()
{
	destroy(getId());
	return m_item;
}

void WorldItem::onUpdate(int ticks)
{
	auto character = SpawnManager::getInstance()->getActivePlayer();
	if (character != nullptr) 
	{
		auto distance = getTransform()->getDistance(character->getTransform());
		if (distance < 4.0f)
		{
			GameManager::getInstance()->createGameObject<PositionBasedPopup>(false, getTransform()->getX(), getTransform()->getY(), 4.0f, character);
			//Create Popup to destroy when this & player are 4> distance apart
		}
	}
}

