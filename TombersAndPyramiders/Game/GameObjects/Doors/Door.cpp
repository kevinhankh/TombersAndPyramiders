#include "Door.h"
#include "DoorController.h"
#include "DummyPilot.h"

Door::Door(std::shared_ptr<ComplexSpriteinfo> spriteInfo, Direction direction, Mode mode, float x, float y) : ComplexSprite(spriteInfo, x, y)
{
	m_mode = mode;
	changeSprite(mode);
	addComponentAsParent<DoorController, BasePossessableController>(this, new DummyPilot());
}

void Door::onUpdate(int ticks)
{
	updateFrames(ticks);
}

void Door::setState(Mode mode)
{
	m_mode = mode;
	switch (m_mode)
	{
	case Door::Open:
		changeSprite(Open);
		break;
	case Door::Closed:
		changeSprite(Closed);
		break;
	default:
		break;
	}
}

Door::Mode Door::getState()
{
	return m_mode;
}