#pragma once
#include "GameObject.h"
class Boss : public GameObject
{
public:
	Boss();
	virtual ~Boss();
	void update_object(const sf::RenderTarget* target);
	void render_object(sf::RenderTarget* target) override;
	void move_object() override;
};
