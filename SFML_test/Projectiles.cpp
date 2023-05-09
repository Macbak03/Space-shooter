#include "Projectiles.h"

Projectiles::Projectiles() : projectile_max_ammount(100000)
{
	this->projectile_spawn_timer_min = 20.f;
	this->projectile_spawn_timer = this->projectile_spawn_timer_min;
}

void Projectiles::spawn_projectile(Player& player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Projectile projectile;
		projectile.init_position(player);
		projectiles.push_back(projectile);
		this->projectile_spawn_timer = 0.f;
	}
	
}

void Projectiles::move_projectiles()
{
	for (auto& element : projectiles) {
		element.move_object();
	}
}

void Projectiles::update_window_collision(const sf::RenderTarget* target)
{
	this->projectiles.erase(std::remove_if(
		this->projectiles.begin(),
		this->projectiles.end(),
		[](Projectile const& projectile) {
			bool window_collision = projectile.get_shape().getGlobalBounds().top <= 0;
			return window_collision;
		}),
		projectiles.end()
			);
}

std::vector<Projectile>& Projectiles::get_projectiles()
{
	return this->projectiles;
}


void Projectiles::update_projectiles(Player& player, const sf::RenderTarget* target)
{
	if (this->projectiles.size() < this->projectile_max_ammount)
	{
		if (this->projectile_spawn_timer >= this->projectile_spawn_timer_min)
		{
			//spawn projectile and reset a timer
			this->spawn_projectile(player);
		}
		else
		{
			this->projectile_spawn_timer += 1.f;
		}
	}
	this->move_projectiles();
	this->update_window_collision(target);
}

void Projectiles::render_projectiles(sf::RenderTarget* target)
{
	for (auto& element : projectiles) {
		element.render_object(target);
	}
}
