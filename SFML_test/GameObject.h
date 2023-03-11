#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
class GameObject
{
private:

public:
	int health;
	float movement_speed;

	virtual void update_object(const sf::RenderTarget* target) = 0;
	virtual void render_object(sf::RenderTarget* target) = 0;
	virtual void move_object() = 0;
	virtual void spawn_object() = 0;
};
