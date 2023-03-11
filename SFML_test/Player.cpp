#include "Player.h"


Player::Player()
{
	this->health = 100;
	this->movement_speed = 3.f;
	this->initShape();
	this->spawn_object();
}

Player::~Player()
{
	
}

void Player::initShape()
{
	this -> p_shape.setFillColor(sf::Color::Blue);
	this -> p_shape.setRadius(20.f);
}

void Player::spawn_object()
{
	this->p_shape.setPosition(sf::Vector2f(390.f,500.f));
}

void Player::updateWindowBounceCollision(const sf::RenderTarget* target)
{
	//left side
	sf::Vector2f playerPosition = this->p_shape.getPosition();
	if (this->p_shape.getGlobalBounds().left <= 0.f)
	{
		this->p_shape.setPosition(0.f, playerPosition.y);
	}
	//right side
	else if (this->p_shape.getGlobalBounds().left + 2*this->p_shape.getRadius() >= target->getSize().x)
	{
		this->p_shape.setPosition(target->getSize().x - 2* this->p_shape.getRadius(), playerPosition.y);
	}

}



void Player::move_object()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->p_shape.move(this->movement_speed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->p_shape.move(-this->movement_speed, 0.f);
	}
}

void Player::update_object(const sf::RenderTarget* target)
{
	//window collision
	this->updateWindowBounceCollision(target);
	//move player
	this->move_object();

}

void Player::render_object(sf::RenderTarget* target)
{
	target->draw(this->p_shape);
}


