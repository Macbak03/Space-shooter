#pragma once
#include "GameObject.h"
#include <vector>
#include "Player.h"
class Enemy : public GameObject
{
private:
	//shape and coordinates of enemy
	sf::RectangleShape e_shape;
	float x, y;
	//spawning enemy stuff
	float enemy_spawn_timer;
	float enemy_spawn_timer_max;
	const int max_enemy_ammount;
	std::vector<sf::RectangleShape> enemies;

	//initializing shape and color of an enemy
	void initShape();
public:
	Enemy();
	virtual ~Enemy();
	void update_object(const sf::RenderTarget* target, Player player);
	void render_object(sf::RenderTarget* target) override;
	void move_object() override;
	void spawn_object(const sf::RenderTarget* target);
	void update_collison(const sf::RenderTarget* target, Player player);
};
