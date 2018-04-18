#include "Obstacle.h"
#include "ObstacleController.h"
#include "ObstaclePilot.h"
#include "DummyPilot.h"

Obstacle::Obstacle(std::shared_ptr<ComplexSpriteInfo> spriteInfo, Vector2* colliderOffset, Direction direction, Mode mode, float x, float y, float scale) : ComplexSprite(spriteInfo, x, y)
{
	getTransform()->setScale(scale);
	m_mode = mode;
	changeSpriteSheet(mode);
	addComponentAsParent<ObstacleController, BasePossessableController>(this, new ObstaclePilot(std::make_shared<TimeInterval>()));
	addComponent<BoxCollider>(this, colliderOffset->getX(), colliderOffset->getY()); //Offset of colliderOffset->getX(), colliderOffset->getY() when offset added
	delete colliderOffset;
}

void Obstacle::onUpdate(int ticks)
{
	updateFrames(ticks);
}

void Obstacle::setState(Mode mode)
{
	m_mode = mode;
	switch (m_mode)
	{
	case Obstacle::Enabled:
		changeSpriteSheet(Disabled);
		getComponent<BoxCollider>()->setDisabled(false);
		break;
	case Obstacle::Disabled:
		changeSpriteSheet(Enabled);
		getComponent<BoxCollider>()->setDisabled(true);
		break;
	default:
		break;
	}
}

Obstacle::Mode Obstacle::getState()
{
	return m_mode;
}