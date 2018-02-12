#include "Camera.h"
#include <memory>
#include "GameManager.h"
#include "HelperFunctions.h"

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

bool Camera::isOnScreen(float transformX, float transformY, float transformScale)
{
	float transformRadius = transformScale / 2.0f;

	float leftBorder = transformX - transformRadius;
	float rightBorder = transformX + transformRadius;
	float topBorder = transformY + transformRadius;
	float bottomBorder = transformY - transformRadius;

	float width = rightBorder - leftBorder;
	float height = topBorder - bottomBorder;

	Transform* cameraTransform = s_activeCamera->getTransform();

	float cameraWidth = getGameWidth();
	float cameraHeight = getGameHeight();
	float cameraX = cameraTransform->getX();
	float cameraY = cameraTransform->getY();

	float cameraLeftBorder = cameraX - 0.5f;
	float cameraRightBorder = cameraX + cameraWidth - 0.5f;
	float cameraTopBorder = cameraY + cameraHeight - 0.5f;
	float cameraBottomBorder = cameraY - 0.5f;

	//Check if in boundary
	return (abs(leftBorder - cameraLeftBorder) * 2 < (width + cameraWidth)) &&
		(abs(bottomBorder - cameraBottomBorder) * 2 < (height + cameraHeight));
}

bool Camera::isOnScreen(Transform* transform)
{
	return isOnScreen(transform->getX(), transform->getY(), transform->getScale());
}