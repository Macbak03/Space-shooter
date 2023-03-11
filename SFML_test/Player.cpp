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
	
	//left
	if (this->p_shape.getGlobalBounds().left <= 0.f)
	{
		this->p_shape.setPosition(0.f, this->p_shape.getGlobalBounds().top);
	}
	//right
	else if (this->p_shape.getGlobalBounds().left + 2*this->p_shape.getRadius() >= target->getSize().x)
	{
		this->p_shape.setPosition(target->getSize().x - 2* this->p_shape.getRadius(), this->p_shape.getGlobalBounds().top);
	}
	//top
	if (this->p_shape.getGlobalBounds().top <= 0.f)
	{
		this->p_shape.setPosition(this->p_shape.getGlobalBounds().left - static_cast<float>(0.10955), 0.f);
	}
	//bottom
	else if (this->p_shape.getGlobalBounds().top + 2 * this->p_shape.getRadius() >= target->getSize().y)
	{
		this->p_shape.setPosition(this->p_shape.getGlobalBounds().left - static_cast < float>(0.10955), target->getSize().y - 2 * this->p_shape.getRadius());
	}
}



void Player::move_object()
{
	//move left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->p_shape.move(-this->movement_speed, 0.f);
	}
	//move right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->p_shape.move(this->movement_speed, 0.f);
	}
	//move top
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->p_shape.move(0.f, -this->movement_speed);
	}
	//move left
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->p_shape.move(0.f , this->movement_speed);
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


