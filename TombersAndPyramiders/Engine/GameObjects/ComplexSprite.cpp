#include "ComplexSprite.h"
#include "SpriteRendererManager.h"
#include "Sprite.h"
#include "Transform.h"
#include "Shader.h"
#include "HelperFunctions.h"

ComplexSprite::ComplexSprite(std::shared_ptr<ComplexSpriteinfo> info, float x, float y, float z, float scale, Shader* nonDefaultShader, int framesPerSecond) : GameObject()
{
	m_spriteInfo = info;

	std::shared_ptr<SpriteRenderer> spriteRenderer = addComponent<SpriteRenderer>(this);
	spriteRenderer->setActiveShader(Shader::getShader(SHADER_SPRITESHEET));

	for (int i = 0; i != info->getSpriteSheetCount(); i++)
	{
		std::string totalPath("Game/Assets/Sprites/" + info->getFilePath(i));
		GLuint texture = SpriteRendererManager::getInstance()->generateTexture(BuildPath((char*)totalPath.c_str()));
		int columns = info->getColumnCount(i);
		int rows = info->getRowCount(i);
		m_sprites.push_back(std::make_shared<SpriteSheet>(texture, columns, rows));
	}

	if (nonDefaultShader != nullptr)
	{
		m_shader = nonDefaultShader;
		spriteRenderer->setActiveShader(m_shader);
	}

	m_currentSpriteSheetIndex = 0;
	spriteRenderer->setActiveSprite(m_sprites[m_currentSpriteSheetIndex]);

	Transform* transform = getTransform();
	transform->setPosition(x, y, z);
	transform->setScale(scale);

	m_framesTilReturn = -1;
	this->m_framesPerSecond = framesPerSecond;
}

void ComplexSprite::setFPS(int fps)
{
	m_framesPerSecond = fps;
}

void ComplexSprite::updateFrames(float delta)
{
	int timeSince = m_timeAlive - m_lastFrame;
	float secondsPerFrame = 1.0f / (float)m_framesPerSecond * 1000;
	if (timeSince > secondsPerFrame)
	{
		m_lastFrame = m_timeAlive;
		nextFrame();
	}
	m_timeAlive += delta;
}


void ComplexSprite::nextFrame()
{
	m_sprites[m_currentSpriteSheetIndex]->nextIndex();
	if (m_framesTilReturn > -1)
	{
		if (--m_framesTilReturn == 0)
		{
			changeSpriteSheet(m_spriteToReturnTo);
			m_framesTilReturn = -1;
		}
	}
}

bool ComplexSprite::changeSpriteSheet(int spriteIndexInComplexInfo)
{
	if (spriteIndexInComplexInfo < 0 || spriteIndexInComplexInfo > m_sprites.size() - 1)
	{
		return false;
	}
	if (spriteIndexInComplexInfo != m_currentSpriteSheetIndex && m_currentSpriteSheetIndex >= 0)
	{
		m_sprites[m_currentSpriteSheetIndex]->resetIndex();
		m_currentSpriteSheetIndex = spriteIndexInComplexInfo;
		getComponent<SpriteRenderer>()->setActiveSprite(m_sprites[spriteIndexInComplexInfo]);

		return true;
	}

	return false;
}

bool ComplexSprite::changeSpriteSheet(std::string spriteName)
{
	int index = m_spriteInfo->getSpriteSheetIndex(spriteName);
	return changeSpriteSheet(index);
}

int ComplexSprite::getCurrentSpriteSheetIndex()
{
	return m_currentSpriteSheetIndex;
}

std::string ComplexSprite::getCurrentSpriteSheetName()
{
	return m_currentSpriteSheetName;
}

bool ComplexSprite::changeSpriteSheet(int spriteIndexInComplexInfo, int returnSprite)
{
	if (spriteIndexInComplexInfo < 0 || spriteIndexInComplexInfo > m_sprites.size() - 1)
	{
		return false;
	}

	if (m_sprites.size() > 0)
	{
		changeSpriteSheet(spriteIndexInComplexInfo);
		m_spriteToReturnTo = returnSprite;
		m_framesTilReturn = m_sprites[returnSprite]->getColumnCount() * m_sprites[returnSprite]->getRowCount();

		return true;
	}

	return false;
}

bool ComplexSprite::changeAnimation(std::string animationName)
{
	// If an animation with that name already exists, return false.
	int animationIndex = m_spriteInfo->getAnimationIndex(m_currentSpriteSheetIndex, animationName);
	
	if (animationIndex != -1)
	{
		return changeAnimation(animationIndex);
	}

	return false;
}

bool ComplexSprite::changeAnimation(int animationIndex)
{
	if (animationIndex < 0)
	{
		return false;
	}


}