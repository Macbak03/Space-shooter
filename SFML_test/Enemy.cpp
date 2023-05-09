#include "enemy.h"
#include "ctime"
#include <iostream>

Enemy::Enemy()
{
	this->movement_speed = 3.f;
	this->init_shape();
}

void Enemy::load_texture()
{
	if (!enemy_texture->loadFromFile("Textures/meteor4.png")) {
		std::cerr << "Could not load texture" << std::endl;
	}
}

void Enemy::init_shape()
{
	this->enemy_texture = new sf::Texture;
	load_texture();
	this->meteor.setTexture(*enemy_texture);
	//this->e_shape.setFillColor(sf::Color::Red);
	//this->e_shape.setSize(sf::Vector2f(20.f, 20.f));
	this->meteor.setScale(sf::Vector2f(0.05f, 0.05f));
}



void Enemy::init_position(const sf::RenderTarget* target)
{
	//setting position of an enemy
	float x;
	x = static_cast<float> (rand() % static_cast<int>((target->getSize().x) - this->meteor.getGlobalBounds().width));
	this->meteor.setPosition(sf::Vector2f(x, 0.f));
}

const sf::Sprite Enemy::get_shape() const
{
	return this->meteor;
}


void Enemy::move_object()
{
	this->meteor.move(0.f, this->movement_speed);
}


void Enemy::render_object(sf::RenderTarget* target)
{
	target->draw(this->meteor);
}


