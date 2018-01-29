#include "Transform.h"
#include <iostream>

Transform::operator GLfloat*()
{
	if (m_values == nullptr)
	{
		m_values = new GLfloat[16]{
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};
	}
	else if (m_values == NULL)
	{
		return nullptr;
	}


	float scaleRotCos = m_scale / GAME_WIDTH * 2.0 * cos(-m_rotation * 3.14159 / 180.0);
	float scaleRotSin = m_scale / GAME_WIDTH * 2.0 * sin(-m_rotation * 3.14159 / 180.0);

	float glX = m_x; //x = 5
	float glY = m_y; //y = 5

	worldPositionToOpenGLPosition(&glX, &glY);

	m_values[0] = scaleRotCos;
	m_values[1] = -scaleRotSin;
	m_values[4] = scaleRotSin;
	m_values[5] = scaleRotCos;
	m_values[12] = glX;
	m_values[13] = glY;

	return m_values;
}

Transform::Transform(GameObject* gameObject) : Component(gameObject)
{
	m_scale = 1.0f;
	m_x = 0.0f;
	m_y = 0.0f;
	m_rotation = 0.0f;
	m_values = nullptr;
}

Transform::~Transform()
{
	if (m_values != nullptr && m_values != NULL)
	{
		delete m_values;
		m_values = NULL;
	}
}

void Transform::addTranslation(float xToAdd, float yToAdd)
{
	m_x += xToAdd;
	m_y += yToAdd;
}

void Transform::setPosition(float newX, float newY)
{
	m_x = newX;
	m_y = newY;
}

void Transform::setPosition(float newX, float newY, float newZ)
{
	m_x = newX;
	m_y = newY;
	m_z = newZ;
}

void Transform::addX(float xToAdd)
{
	m_x += xToAdd;
}

void Transform::addY(float yToAdd)
{
	m_y += yToAdd;
}

void Transform::addZ(float zToAdd)
{
	m_z += zToAdd;
}

void Transform::setX(float newX)
{
	m_x = newX;
}

void Transform::setY(float newY)
{
	m_y = newY;
}

void Transform::setZ(float newZ)
{
	m_z = newZ;
}

void Transform::addRotation(float byDegrees)
{
	m_rotation += byDegrees;
}

void Transform::setRotation(float newAngle)
{
	m_rotation = newAngle;
}

void Transform::setScale(float newScale)
{
	m_scale = newScale;
}

float Transform::getX()
{
	return m_x;
}

float Transform::getY()
{
	return m_y;
}

float Transform::getZ()
{
	return m_z;
}

float Transform::getRotation()
{
	return m_rotation;
}

float Transform::getScale()
{
	return m_scale;
}

void Transform::addScale(float toAdd)
{
	m_scale += toAdd;
}