#include "Player.h"
#include <iostream>


Player::Player()
{
	this->health = 100;
	this->movement_speed = 7.f;
	this->points = 0;
	this->init_shape();
	this->spawn_object();
}

void Player::load_texture()
{
	if (!player_texture.loadFromFile("Textures/spiked_ship_3.png")) {
		std::cerr << "Could not load texture" << std::endl;
	}
}

void Player::init_shape()
{
	load_texture();
	this -> starship.setTexture(player_texture);
	//this -> p_shape.setFillColor(sf::Color::Blue);
	//this -> p_shape.setSize(sf::Vector2f(30.f, 30.f));
	this -> starship.setScale(sf::Vector2f(0.2f, 0.2f));
}
void Player::spawn_object()
{
	
	this->starship.setPosition(sf::Vector2f(390.f,500.f));
}

void Player::update_window_bounce_collision(const sf::RenderTarget* target)
{
	
	//left
	if (this->starship.getGlobalBounds().left <= 0.f)
	{
		this->starship.setPosition(0.f, this->starship.getGlobalBounds().top);
	}
	//right
	else if (this->starship.getGlobalBounds().left + this->starship.getGlobalBounds().width >= target->getSize().x)
	{
		this->starship.setPosition(target->getSize().x - this->starship.getGlobalBounds().width, this->starship.getGlobalBounds().top);
	}
	//top
	if (this->starship.getGlobalBounds().top <= 0.f)
	{
		this->starship.setPosition(this->starship.getGlobalBounds().left , 0.f);
	}
	//bottom
	else if (this->starship.getGlobalBounds().top +  this->starship.getGlobalBounds().height >= target->getSize().y)
	{
		this->starship.setPosition(this->starship.getGlobalBounds().left, target->getSize().y - this->starship.getGlobalBounds().height);
	}
}



void Player::move_object()
{
	//move left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->starship.move(-this->movement_speed, 0.f);
	}
	//move right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->starship.move(this->movement_speed, 0.f);
	}
	//move top
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->starship.move(0.f, -this->movement_speed);
	}
	//move left
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->starship.move(0.f , this->movement_speed);
	}
}

const sf::Sprite& Player::get_shape() const
{
	return this->starship;
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
	target->draw(this->starship);
}


