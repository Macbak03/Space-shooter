#pragma once
#include "GameObject.h"
#include "Projectile.h"

class Enemy : public GameObject
{
private:
	//shape and coordinates of enemy
	sf::RectangleShape e_shape;
	sf::Texture* enemy_texture;
	sf::Sprite meteor;

	//initializing shape and color of an enemy
	void init_shape() override;
public:
	Enemy();
	void render_object(sf::RenderTarget* target) override;
	void move_object() override;
	void init_position(const sf::RenderTarget* target);
	const sf::Sprite get_shape() const;
	void load_texture();
	
};
