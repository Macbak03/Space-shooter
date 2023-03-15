#include "enemy.h"
#include "ctime"

Enemy::Enemy()
{
	this->movement_speed = 1.f;
	this->init_shape();
}


void Enemy::init_shape()
{
	this->e_shape.setFillColor(sf::Color::Red);
	this->e_shape.setSize(sf::Vector2f(20.f, 20.f));
}



void Enemy::init_position(const sf::RenderTarget* target)
{
	//setting position of an enemy
	float x;
	x = static_cast<float> (rand() % static_cast<int>((target->getSize().x) - this->e_shape.getSize().x));
	this->e_shape.setPosition(sf::Vector2f(x, 0.f));
}

const sf::RectangleShape Enemy::get_shape() const
{
	return this->e_shape;
}



void Enemy::move_object()
{
	this->e_shape.move(0.f, this->movement_speed);
}


void Enemy::render_object(sf::RenderTarget* target)
{
	target->draw(this->e_shape);
}


