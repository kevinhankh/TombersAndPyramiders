#include "Camera.h"
#include <memory>
#include "GameManager.h"

std::shared_ptr<Camera> Camera::s_activeCamera = GameManager::getInstance()->createGameObject<Camera>(true);

Camera::Camera() : GameObject()
{
	m_init = false;
}

void Camera::applyRenderFilters(SpriteRendererManager* rendererManager)
{
	rendererManager->renderPass();
}

void Camera::setActiveCamera(std::shared_ptr<Camera> camera)
{
	s_activeCamera->notifyInactivity();
	s_activeCamera = camera;
}

std::shared_ptr<Camera> Camera::getActiveCamera()
{
	return s_activeCamera;
}

void Camera::notifyInactivity()
{
	destroy(s_activeCamera);
	s_activeCamera = nullptr;
}

void Camera::ensureInit()
{
	if (!m_init)
	{
		init();
		m_init = true;
	}
}

void Camera::init() {}