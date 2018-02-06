#pragma once

#include "Collider.h"
#include "Vector2.h"

class BoxCollider : public Collider {
private:
	float m_width, m_height;
	Vector2 m_corners[4];
public:
	BoxCollider(float width, float height);
	float getWidth();
	float getHeight();
	void setWidth(float width);
	void setHeight(float height);
	void updateCorners();
};