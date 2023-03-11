#pragma once
#include "GameObject.h"
class Player : public GameObject
{
private:
	sf::CircleShape p_shape;
	void initShape();

public:
	Player();
	virtual ~Player();
	void spawn_object() override;
	void updateWindowBounceCollision(const sf::RenderTarget* target);
	void update_object(const sf::RenderTarget* target) override;
	void render_object(sf::RenderTarget* target) override;
	void move_object() override;
};
