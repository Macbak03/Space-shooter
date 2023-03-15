#pragma once

#include "Projectile.h"
#include <vector>

class Projectiles : public Projectile
{
private:
	std::vector<Projectile> projectiles;
	float projectile_spawn_timer;
	float projectile_spawn_timer_min;
	const int projectile_max_ammount;
public:
	Projectiles();
	void spawn_projectile(Player& player);
	void render_projectiles(sf::RenderTarget* target);
	void update_projectiles(Player& player, const sf::RenderTarget* target);
	void update_window_collision(const sf::RenderTarget* target);
	void move_projectiles();
	std::vector<Projectile>& get_projectiles();
};

