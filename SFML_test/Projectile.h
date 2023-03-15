#pragma once

#include "GameObject.h"
#include "Player.h"


class Projectile : public GameObject
{
private:
	sf::RectangleShape proj_shape;
	void init_shape() override;
public:
	Projectile();
	void init_position(Player player);
	void move_object() override;
	void render_object(sf::RenderTarget* target) override;
	const sf::RectangleShape& get_shape() const;
};

