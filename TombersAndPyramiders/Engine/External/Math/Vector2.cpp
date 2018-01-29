#include "Vector2.h"

Vector2::Vector2(float x, float y) : m_x(x), m_y(y)
{
}

void Vector2::setX(float value)
{
	m_x = value;
}

float Vector2::getX()
{
	return m_x;
}

void Vector2::setY(float value)
{
	m_y = value;
}

float Vector2::getY()
{
	return m_y;
}

float Vector2::getMagnitude()
{
	m_magnitude = sqrt(pow(m_x, 2) + pow(m_y, 2));
	return m_magnitude;
}

void Vector2::normalize()
{
	getMagnitude();
	m_x /= m_magnitude;
	m_y /= m_magnitude;
}


//OPERATORS

Vector2* Vector2::operator*(float value)
{
	m_x *= value;
	m_y *= value;
	return this;
}

Vector2* Vector2::operator/(float value)
{
	m_x /= value;
	m_y /= value;
	return this;
}

Vector2* Vector2::operator+(Vector2 v)
{
	m_x += v.getX();
	m_y += v.getY();
	return this;
}

Vector2* Vector2::operator-(Vector2 v)
{
	m_x -= v.getX();
	m_y -= v.getY();
	return this;
}

Vector2* Vector2::operator-()
{
	m_x = -m_x;
	m_y = -m_y;
	return this;
}

void Vector2::rotateVector(float radians)
{
	float tempCos = cos(radians);
	float tempSin = sin(radians);
	m_x = tempCos * m_x - tempSin * m_y;
	m_y = tempSin * m_x + tempCos * m_y;
}

/*ignore but dont delete

float Vector::getRotation() {
	if (_x > 0 && _y > 0) {
		_rotation = atan(_y / _x);
	}
	else if (_x < 0 && _y > 0) {
		_rotation = atan(-_x / _y) + M_PI / 2;
	}
	else if (_x < 0 && _y < 0){
		_rotation = atan(_y / _x) + M_PI;
	}
	else if (_x > 0 && _y < 0) {
		_rotation = atan(_x / -_y) + 3 * M_PI / 2;
	}
	else {
		_rotation = 0;
	}
	return _rotation;
}
*/