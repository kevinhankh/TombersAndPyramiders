#include "GhostReceiverPilot.h"
#include "GhostController.h"
#include "Receiver.h"
#include "GhostCharacter.h"

GhostReceiverPilot::GhostReceiverPilot()
{
	m_lastNetworkVector = Vector2(0, 0);
	m_hasInit = false;
	
}

void GhostReceiverPilot::onStart()
{
	if (!m_hasInit) 
	{
		auto receiver = m_controller->getGameObject()->getComponent<Receiver>();
		if (receiver != nullptr) 
		{
			/*receiver->Subscribe("GHOSTTRIGGER", [](std::map<std::string, void*> data) -> void
			{
				if (!((GhostCharacter*)data["this"])->getComponent<GhostController>()->tryTrigger())
				{
					std::cout << "Sync Error on character receiving Trigger event. Should only be called on successful triggering, however receiver could not invoke a trigger." << std::endl;
				}
			}, this);*/
			receiver->Subscribe("GHOSTPOSSESS", [](std::map<std::string, void*> data) -> void
			{
				std::shared_ptr<BasePossessableController> closest;
				auto ghostController = ((GhostCharacter*)data["this"])->getComponent<GhostController>();
				if (ghostController->tryPossessClosest(closest)) //Try and possess, make sure its close enough
				{
					auto ghostPilot = dynamic_cast<GhostReceiverPilot*>(ghostController->getPilot());
					if (ghostPilot != nullptr) 
					{
						ghostPilot->setPossession(closest); //If our controller successfully possessed it, update our Pilot to know so
					}
				} else {
					std::cout << "Sync Error on character receiving Trigger event. Should only be called on successful triggering, however receiver could not invoke a trigger." << std::endl;
				}
			}, this);
			receiver->Subscribe("GHOSTUNPOSSESS", [](std::map<std::string, void*> data) -> void
			{
				auto ghostController = ((GhostCharacter*)data["this"])->getComponent<GhostController>();
				auto ghostPilot = dynamic_cast<GhostReceiverPilot*>(ghostController->getPilot());
				ghostPilot->setPossession(nullptr);
			}, this);
		}

		m_hasInit = true;
	}
}

void GhostReceiverPilot::setPossession(std::shared_ptr<BasePossessableController> possession)
{
	if (possession != nullptr) 
	{
		// If we are trying to possess something, possess it
		m_controller->swapPilots(dynamic_cast<BaseController*>(possession.get()));
		m_possessableController = possession;
		m_possessableController->onPossessionStart();
	}
	else 
	{
		// If we are trying to stop possessing, stop possessing
		GhostController* ghostControllerRaw = dynamic_cast<GhostController*>(m_controller);
		Transform* possessTrans = m_possessableController->getGameObject()->getTransform();
		ghostControllerRaw->getGameObject()->getTransform()->setPosition(possessTrans->getX(), possessTrans->getY());
		m_possessableController->swapPilots(ghostControllerRaw);
		m_possessableController->onPossessionEnd();
		m_possessableController = nullptr;
		ghostControllerRaw->getGameObject()->getTransform()->setScale(1.0f);
		ghostControllerRaw->stopPossessing();
	}
}

void GhostReceiverPilot::onUpdate(int ticks)
{
	if (!m_hasInit) {
		onStart();
	}
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