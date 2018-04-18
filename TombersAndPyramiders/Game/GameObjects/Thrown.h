#pragma once

#include "ComplexSprite.h"
#include "Invokable.h"

class Thrown : public ComplexSprite, public Invokable
{
private:
    bool m_popupActive;
    std::shared_ptr<ComplexSpriteInfo> createSpriteInfo();
    int m_brightness;
    bool m_activated;
    int m_counter;

public:
	Thrown();
	~Thrown();

	void onStart();
	void onUpdate(int ticks);
    void onEnd() {};
    void trigger();
};