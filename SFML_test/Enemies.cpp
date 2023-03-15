#include "Enemies.h"

Enemies::Enemies() : max_enemy_ammount(7)
{
	this->enemy_spawn_timer_min = 100.f;
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


void Enemies::update_collision(const sf::RenderTarget* target, Player* player, Projectile* projectile)
{
	this->enemies.erase(std::remove_if(
		this->enemies.begin(),
		this->enemies.end(),
		[target, player](Enemy const& enemy, Projectile const& projectile) {
			//collision with bounds of the window
			bool window_collision = enemy.get_shape().getGlobalBounds().top + enemy.get_shape().getSize().y >= target->getSize().y;
			//collision with player
			bool player_collision = player->get_shape().getGlobalBounds().intersects(enemy.get_shape().getGlobalBounds());
			//collision with projectile
			bool projectile_collision = projectile.get_shape().getGlobalBounds().intersects(enemy.get_shape().getGlobalBounds());
			if (player_collision) {
				player->health -= 10;
			}
			return window_collision || player_collision || projectile_collision;

		}),
		this->enemies.end()
			);


	//projectile.get_projectiles().erase(std::remove_if(
	//	projectile.get_projectiles().begin(),
	//	projectile.get_projectiles().end(),
	//	[&e_shape](sf::RectangleShape const& missle) {
	//		//projectile collision with enemy
	//		bool collision = missle.getGlobalBounds().intersects(e_shape.getGlobalBounds());
	//		return collision;

	//	}),
	//	projectile.get_projectiles().end()
	//		);\
	

	//for (int j = 0; j < projectile.get_projectiles().size(); j++)
	//{
	//	if (projectile.get_projectiles()[j].getGlobalBounds().intersects(this->enemies[i].getGlobalBounds()))

	//	{
	//		this->enemies.erase(this->enemies.begin() + i);
	//		//projectile.get_projectiles().erase(projectile.get_projectiles().begin() + j);
	//	}
	//}

}

void Enemies::update_enemies(Player& player, const sf::RenderTarget* target, Projectile& projectile)
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
	this->update_collision(target, &player, &projectile);
}

void Enemies::render_enemies(sf::RenderTarget* target)
{
	for (auto& element : enemies) {
		element.render_object(target);
	}
}
