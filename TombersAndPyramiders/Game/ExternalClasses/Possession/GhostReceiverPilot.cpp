#include "GhostReceiverPilot.h"
#include "GhostController.h"

GhostReceiverPilot::GhostReceiverPilot()
{
	m_lastNetworkVector = Vector2(0, 0);
}

void GhostReceiverPilot::onStart()
{

}

void GhostReceiverPilot::onUpdate(int ticks)
{
	GhostController* ghostControllerRaw = dynamic_cast<GhostController*>(m_controller);
	if (ghostControllerRaw != nullptr && m_updatesSinceNewMovement < m_updatesUntilInvalid)
	{
		ghostControllerRaw->move(m_lastNetworkVector);
		m_updatesSinceNewMovement++;
	}
}

void GhostReceiverPilot::onEnd()
{

}

void GhostReceiverPilot::setMovement(Vector2 vec, int updates) {
	m_lastNetworkVector.setX(vec.getX());
	m_lastNetworkVector.setY(vec.getY());
	m_updatesUntilInvalid = updates;
	m_updatesSinceNewMovement = 0;
}