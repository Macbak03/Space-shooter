#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
/*
	Class that acts llike a game engine.
	Wraper class
*/

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	Player player;
	Enemy enemy;

	int points;

	sf::Font font;
	sf::Text text;

	bool endGame;
	//Functions
	void initVariables();
	void initWindow();
	void initFont();
	void initText();

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();
	//Accessors
	const bool getWindowIsOpen();
	//Functions
	void pollEvents();
	void updateGui();
	void update();
	void renderGui(sf::RenderTarget* target);
	void render();
};

