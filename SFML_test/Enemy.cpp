#include "enemy.h"
#include "ctime"

Enemy::Enemy() : max_enemy_ammount(7)
{
	this->movement_speed = 1.f;
	this->init_shape();
	this->enemy_spawn_timer_max = 100.f;
	this-> enemy_spawn_timer = this->enemy_spawn_timer_max;
}


void Enemy::init_shape()
{
	this->e_shape.setFillColor(sf::Color::Red);
	this->e_shape.setSize(sf::Vector2f(20.f, 20.f));
}



void Enemy::spawn_object(const sf::RenderTarget* target)
{
	//setting position of an enemy
	x = static_cast<float> (rand() % static_cast<int>((target->getSize().x) - this->e_shape.getSize().x));
	this->e_shape.setPosition(sf::Vector2f(x, 0.f));

	//adding enemy to a vector
	this->enemies.push_back(this->e_shape);

}

const sf::RectangleShape Enemy::get_shape() const
{
	return this->e_shape;
}

void Enemy::update_collison(const sf::RenderTarget* target, Player player, Projectile projectile)
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		//collision with bounds of the window
		if (this->enemies[i].getGlobalBounds().top + this->e_shape.getSize().y >= target->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			player.health -= 10;
		}
		//collision with player
		else if (player.get_shape().getGlobalBounds().intersects(this->enemies[i].getGlobalBounds()))

		{
			this->enemies.erase(this->enemies.begin() + i);
			player.health -= 10;
		}
		//collision with projectile
		for (int j = 0; j < projectile.get_projectiles().size(); j++)
		{
			if (projectile.get_projectiles()[j].getGlobalBounds().intersects(this->enemies[i].getGlobalBounds()))

			{
				this->enemies.erase(this->enemies.begin() + i);
				//projectile.get_projectiles().erase(projectile.get_projectiles().begin() + j);
			}
		}
		 
	}

}

void Enemy::move_object()
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].move(0.f, this->movement_speed);
	}
}

void Enemy::update_object(const sf::RenderTarget* target, Player player, Projectile projectile)
{
	if (this->enemies.size() < this->max_enemy_ammount)
	{
		if (this->enemy_spawn_timer >= this->enemy_spawn_timer_max)
		{
			//spawn enemy and reset a timer
			this->spawn_object(target);
			this->enemy_spawn_timer = 0.f;
		}
		else
		{
			this->enemy_spawn_timer += 1.f;
		}
	}
	this->update_collison(target, player, projectile);
	this->move_object();

}

void Enemy::render_object(sf::RenderTarget* target)
{

	for (auto& e : this->enemies)
	{
		target->draw(e);
	}
	
}


