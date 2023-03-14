#include "Projectile.h"



Projectile::Projectile() : proj_max(100)
{
	this->movement_speed = 10.f;
	this->proj_spawn_timer_min = 50.f;
	this->proj_spawn_timer = this->proj_spawn_timer_min;
	init_shape();
}

void Projectile::init_shape()
{
	this->proj_shape.setSize(sf::Vector2f(3.f, 13.f));
	this->proj_shape.setFillColor(sf::Color::White);
	this->proj_shape.setOutlineColor(sf::Color::Magenta);
	this->proj_shape.setOutlineThickness(1);
}

void Projectile::spawn_object(Player player)
{
	this-> x = player.get_shape().getGlobalBounds().left + player.get_shape().getGlobalBounds().width / 2 - proj_shape.getSize().x / 3;
	this->y = player.get_shape().getGlobalBounds().top - proj_shape.getSize().y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		this->proj_shape.setPosition(sf::Vector2f(x,y));
		this->projectiles.push_back(proj_shape);
	}
}

const sf::RectangleShape& Projectile::get_shape() const
{
	return this->proj_shape;
}

void Projectile::move_object()
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		this->projectiles[i].move(0.f, - this->movement_speed);
	}
	
}

void Projectile::update_object(Player player)
{
	if (this->projectiles.size() < this->proj_max)
	{
		if (this->proj_spawn_timer >= this->proj_spawn_timer_min)
		{
			//spawn projectile and reset a timer
			this->spawn_object(player);
			this->proj_spawn_timer = 0.f;
		}
		else
		{
			this->proj_spawn_timer += 1.f;
		}
	}
	this->move_object();
}

void Projectile::render_object(sf::RenderTarget* target)
{
	for (auto& e : projectiles)
	{
		target->draw(e);
	}
}




