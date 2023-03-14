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
	virtual void init_shape() = 0;
	virtual void render_object(sf::RenderTarget* target) = 0;
	virtual void move_object() = 0;
};

