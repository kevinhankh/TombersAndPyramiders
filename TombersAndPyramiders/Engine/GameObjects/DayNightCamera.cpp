#include "DayNightCamera.h"
#include "SharedConstants.h"
#include "GameManager.h"
#include "SpriteRendererManager.h"
#include "HelperFunctions.h"
#include "Light.h"

void DayNightCamera::init()
{
	m_regularPass.init();
	m_fogOfWarPass.init();
}

inline float lerp(float t, float a, float b)
{
	return (1 - t)*a + t*b;
}

void DayNightCamera::updateFogOfWarMask() 
{
	int gameWidth = SCREEN_WIDTH;
	int gameHeight = SCREEN_HEIGHT;
	std::vector<unsigned char> bytes(gameWidth * gameHeight * 4);
	//for(int x = 0; x < gameWidth; x++) {
	//	for(int y = 0; y < gameHeight; y++) {
	//		bytes[(y * SCREEN_WIDTH + x) * 4] = 62;
	//		bytes[(y * SCREEN_WIDTH + x) * 4 + 1] = 52;
	//		bytes[(y * SCREEN_WIDTH + x) * 4 + 1] = 25;
	//		bytes[(y * SCREEN_WIDTH + x) * 4 + 3] = 255;
	//	}
	//}
	for(int i = 0; i < gameWidth * gameHeight * 4; i += 4) 
	{
		//bytes[i] = 10 + (i % 6) * 5;
		//bytes[i + 1] = 15 + (i % 5) * 3;
		//bytes[i + 2] = 5 + (i % 4) * 3;
		bytes[i + 3] = 240;//230 + (i % 8) * 3;
	}

	auto objectsInBounds = GameManager::getInstance()->getObjectsInBounds(getTransform()->getX(), getTransform()->getY(), getGameWidth(), getGameHeight());

	for(int i = 0; i < objectsInBounds.size(); i++)
	{
		auto lightComponent = objectsInBounds[i]->getComponent<Light>();
		if (lightComponent != nullptr) {
			int lightR = 0;
			int lightG = 0;
			int lightB = 0;
			float lightSize = lightComponent->getLight(lightR, lightG, lightB);

			float lightSizePixels = lightSize * getUnitSize();

			auto lightTransform = objectsInBounds[i]->getTransform();
			if (isOnScreen(lightTransform)) {
				int screenX = SCREEN_WIDTH / 2.0 - ((getTransform()->getX() - lightTransform->getX()) * getUnitSize());
				int screenY = SCREEN_HEIGHT / 2.0f - ((getTransform()->getY() - lightTransform->getY()) * getUnitSize());
				float dist = getTransform()->getDistance(lightTransform);
				
				//25% of screen width gives (5/(20/2) == 5/10 == 0.5)
				//0% of screen width gives (0/(20/2) == 0/10 == 0.0)
				float t = 1 - std::min( std::max( dist / (getGameHeight() / 2.0f), 0.0f ), 1.0f);
				unsigned char r = lerp(0.0f, lightR, t);
				unsigned char g = lerp(0.0f, lightG, t);
				unsigned char b = lerp(0.0f, lightB, t);
				unsigned char a = lerp(0.0f, 255.0f, t);

				std::cout << "FOR DIF: " << (getTransform()->getX() - lightTransform->getX()) << "," << (getTransform()->getY() - lightTransform->getY()) << std::endl;
				std::cout << "Dist: " << dist << " | T:" << std::endl; 
				std::cout << "RGBA: " << (int)r << " " << (int)g << " " << (int)b << " " << (int)a << std::endl;
				
				int lightRadiusPixels = lightSizePixels / 2.0f;
				
				for(int x = -lightRadiusPixels; x < lightRadiusPixels; x++ ) {
					for(int y = -lightRadiusPixels; y < lightRadiusPixels; y++) {
						int pos = ((screenY + y) * SCREEN_WIDTH + (screenX) + x) * 4;
						if (pos >= 0 && pos < gameWidth * gameHeight * 4) {
							int culmulativeDist = abs(x) + abs(y);
							if (culmulativeDist < lightRadiusPixels) {
								bytes[pos] = r;//std::max(bytes[pos], r);
								bytes[pos + 1] = g;//std::max(bytes[pos + 1], g);
								bytes[pos + 2] = b;//std::max(bytes[pos + 2], b);
								bytes[pos + 3] = a;//((float)culmulativeDist / (float)lightRadiusPixels) * a;
							}
						}
					}
				}
	
				//if (screenX >= 0 && screenY >= 0 && screenY <= gameHeight) {
				//	bytes[(screenY * SCREEN_WIDTH + screenX) * 4] = 255;
				//	bytes[(screenY * SCREEN_WIDTH + screenX) * 4 + 1] = 255;
				//	bytes[(screenY * SCREEN_WIDTH + screenX) * 4 + 2] = 0;
				//}
			}
		}
	}

	SpriteRendererManager::getInstance()->generateTexture(gameWidth, gameHeight, bytes, &m_fogOfWarMask);
}

int testCounter = 0;
bool full = false;
void DayNightCamera::applyRenderFilters(SpriteRendererManager* rendererManager)
{
	ensureInit();
	updateFogOfWarMask();
	m_regularPass.bindFrameBuffer();
	rendererManager->renderPass();
	m_regularPass.unbindFrameBuffer();
	rendererManager->renderFogOfWar(m_fogOfWarMask, m_regularPass);
}