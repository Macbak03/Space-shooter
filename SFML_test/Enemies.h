#pragma once
#include "Enemy.h"
#include <vector>
#include "Projectiles.h"

class Enemies : public Enemy
{
private:
	std::vector<Enemy> enemies;
	float enemy_spawn_timer;
	float enemy_spawn_timer_min;
	const int max_enemy_ammount;
public:
	Enemies();
	void spawn_enemies(const sf::RenderTarget* target);
	void render_enemies(sf::RenderTarget* target);
	void update_enemies(Player& player, const sf::RenderTarget* target, Projectiles& projectiles);
	void update_collision(const sf::RenderTarget* target, Player* player, Projectiles* projectiles);
	void move_enemies();
};

