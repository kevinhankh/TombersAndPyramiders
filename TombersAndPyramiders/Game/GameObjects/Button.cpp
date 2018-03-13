#include "Button.h"

Button::Button(string text, string spriteName, float x, float y, float z, float scale) : SimpleSprite(spriteName, x, y, z, scale)
{
	m_text = text;
}

Button::~Button()
{

}

void Button::setText(string text)
{
	m_text = text;
}

string Button::getText()
{
	return m_text;
}

void Button::OnClicked()
{

}

void Button::OnHover()
{

}

void Button::OnUnhover()
{

}