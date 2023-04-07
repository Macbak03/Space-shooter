#include "Projectile.h"

//TODO: repair vector capacity error, when projectile colides with an enemy near a top window bound, add erasing projectile, while coliding with an enemy

Projectile::Projectile()
{
	this->movement_speed = 12.f;
	init_shape();
}

void Projectile::init_shape()
{
	
	this->proj_shape.setSize(sf::Vector2f(3.f, 13.f));
	this->proj_shape.setFillColor(sf::Color::White);
	this->proj_shape.setOutlineColor(sf::Color::Magenta);
	this->proj_shape.setOutlineThickness(1);
	
}

void Projectile::init_position(Player player)
{
	float x = player.get_shape().getGlobalBounds().left + player.get_shape().getGlobalBounds().width / 2 - proj_shape.getSize().x / 3;
	float y = player.get_shape().getGlobalBounds().top - proj_shape.getSize().y;
	this->proj_shape.setPosition(sf::Vector2f(x, y));
}

const sf::RectangleShape& Projectile::get_shape() const
{
	return this->proj_shape;
}



void Projectile::move_object()
{
	proj_shape.move(0.f, -movement_speed);
}


void Projectile::render_object(sf::RenderTarget* target)
{
	target->draw(this->proj_shape);
}
