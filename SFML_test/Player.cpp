#include "Player.h"


Player::Player()
{
	this->health = 100;
	this->movement_speed = 5.f;
	this->init_shape();
	this->spawn_object();
}


void Player::init_shape()
{
	this -> p_shape.setFillColor(sf::Color::Blue);
	this -> p_shape.setSize(sf::Vector2f(30.f, 30.f));
}

void Player::spawn_object()
{
	this->p_shape.setPosition(sf::Vector2f(390.f,500.f));
}

void Player::update_window_bounce_collision(const sf::RenderTarget* target)
{
	
	//left
	if (this->p_shape.getGlobalBounds().left <= 0.f)
	{
		this->p_shape.setPosition(0.f, this->p_shape.getGlobalBounds().top);
	}
	//right
	else if (this->p_shape.getGlobalBounds().left + this->p_shape.getGlobalBounds().width >= target->getSize().x)
	{
		this->p_shape.setPosition(target->getSize().x - this->p_shape.getGlobalBounds().width, this->p_shape.getGlobalBounds().top);
	}
	//top
	if (this->p_shape.getGlobalBounds().top <= 0.f)
	{
		this->p_shape.setPosition(this->p_shape.getGlobalBounds().left , 0.f);
	}
	//bottom
	else if (this->p_shape.getGlobalBounds().top +  this->p_shape.getGlobalBounds().height >= target->getSize().y)
	{
		this->p_shape.setPosition(this->p_shape.getGlobalBounds().left, target->getSize().y - this->p_shape.getGlobalBounds().height);
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

const sf::RectangleShape& Player::get_shape() const
{
	return this->p_shape;
}




void Player::update_object(const sf::RenderTarget* target)
{
	//window collision
	this->update_window_bounce_collision(target);
	//move player
	this->move_object();

}

void Player::render_object(sf::RenderTarget* target)
{
	target->draw(this->p_shape);
}


