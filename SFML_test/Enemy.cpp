#include "enemy.h"
#include "ctime"

Enemy::Enemy() : max_enemy_ammount(7)
{
	this->enemy_ammount = 0;
	this->health = 10;
	this->initShape();
	this->spawn_object();

}

Enemy::~Enemy()
{
}

void Enemy::initShape()
{
	this->e_shape.setFillColor(sf::Color::Red);
	this->e_shape.setSize(sf::Vector2f(20.f, 20.f));
}

void Enemy::spawn_object()
{
	x = static_cast<float> (rand() % 800);
	this->e_shape.setPosition(sf::Vector2f(x, 0.f));
}

void Enemy::move_object()
{
}

void Enemy::update_object(const sf::RenderTarget* target)
{
}

void Enemy::render_object(sf::RenderTarget* target)
{
	target->draw(this->e_shape);
}


