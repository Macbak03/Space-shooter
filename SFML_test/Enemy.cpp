#include "enemy.h"
#include "ctime"

Enemy::Enemy() : max_enemy_ammount(7)
{
	this->movement_speed = 2.f;
	this->health = 10;
	this->initShape();
	this->enemy_spawn_timer_max = 1000.f;
	this-> enemy_spawn_timer = this->enemy_spawn_timer_max;
}

Enemy::~Enemy()
{
}

void Enemy::initShape()
{
	this->e_shape.setFillColor(sf::Color::Red);
	this->e_shape.setSize(sf::Vector2f(20.f, 20.f));
}

void Enemy::spawn_object(const sf::RenderTarget* target)
{
	x = static_cast<float> (rand() % static_cast<int>((target->getSize().x) - this->e_shape.getSize().x));
	this->e_shape.setPosition(sf::Vector2f(x, 0.f));

	this->enemies.push_back(this->e_shape);

	this->move_object();
}

void Enemy::move_object()
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].move(0.f, this->movement_speed);
	}
}

void Enemy::update_object(const sf::RenderTarget* target)
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
	this->move_object();
}

void Enemy::render_object(sf::RenderTarget* target)
{
	for (auto& e : this->enemies)
	{
		target->draw(e);
	}
	
}


