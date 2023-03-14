#pragma once
#include "GameObject.h";
#include "Player.h"
#include "Enemy.h"

class Projectile : public GameObject
{
private:
	sf::RectangleShape proj_shape;
	float x, y;
	const int proj_max;
	float proj_spawn_timer;
	float proj_spawn_timer_min;


	std::vector<sf::RectangleShape> projectiles;

	void init_shape() override;
public:
	Projectile();
	void spawn_object(Player player);
	void move_object() override;
	void update_object(Player player);
	void render_object(sf::RenderTarget* target) override;
	
	const sf::RectangleShape& get_shape() const;

};

