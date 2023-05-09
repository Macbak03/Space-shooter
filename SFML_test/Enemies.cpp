#include "Enemies.h"

Enemies::Enemies() : max_enemy_ammount(7)
{
	this->enemy_spawn_timer_min = 50.f;
	this->enemy_spawn_timer = this->enemy_spawn_timer_min;
}

void Enemies::spawn_enemies(const sf::RenderTarget* target)
{
	Enemy enemy;
	enemy.init_position(target);
	this->enemies.push_back(enemy);
}


void Enemies::move_enemies()
{
	for (auto& element : enemies) {
		element.move_object();
	}
}


void Enemies::update_collision(const sf::RenderTarget* target, Player* player, Projectiles* projectiles)
{
	this->enemies.erase(std::remove_if(
		this->enemies.begin(),
		this->enemies.end(),
		[target, player, projectiles](Enemy const& enemy) {
			//collision with bounds of the window
			bool window_collision = enemy.get_shape().getGlobalBounds().top + enemy.get_shape().getSize().y >= target->getSize().y;
			//collision with player
			bool player_collision = player->get_shape().getGlobalBounds().intersects(enemy.get_shape().getGlobalBounds());
			//collision with projectile
			bool projectile_enemy_collision = false;
			for (auto& element : projectiles->get_projectiles()) {
				projectile_enemy_collision |= element.get_shape().getGlobalBounds().intersects(enemy.get_shape().getGlobalBounds());
			}
			//erasing projectile while hit an enemy
			auto& projectiles_vector = projectiles->get_projectiles();
			projectiles_vector.erase(std::remove_if(projectiles_vector.begin(), projectiles_vector.end(), [enemy](Projectile const& projectile) {
				bool projectile_collision = projectile.get_shape().getGlobalBounds().intersects(enemy.get_shape().getGlobalBounds());
			return projectile_collision;
				}),
				projectiles_vector.end()
			);
			if (player_collision) {
				player->health -= 10;
			}
			if (projectile_enemy_collision)
			{
				player->points += 1;
			}
			return window_collision || player_collision || projectile_enemy_collision;

		}),
		this->enemies.end()
			);


}

void Enemies::update_enemies(Player& player, const sf::RenderTarget* target, Projectiles& projectiles)
{
	if (this->enemies.size() < this->max_enemy_ammount)
	{
		if (this->enemy_spawn_timer >= this->enemy_spawn_timer_min)
		{
			//spawn enemy and reset a timer
			this->spawn_enemies(target);
			this->enemy_spawn_timer = 0.f;
		}
		else
		{
			this->enemy_spawn_timer += 1.f;
		}
	}
	this->move_enemies();
	this->update_collision(target, &player, &projectiles);
}

void Enemies::render_enemies(sf::RenderTarget* target)
{
	for (auto& element : enemies) {
		element.render_object(target);
	}
}
