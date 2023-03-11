#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

void Game::initVariables()
{
	this->window = nullptr;
	this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "The Game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::getWindowIsOpen()
{
	return this->window->isOpen();
}


void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
				break;
			}
		}
	}
}

//Functions
void Game::update()
{
	this->pollEvents();
	this->player.update_object(this->window);
}

void Game::render()
{
	/*
		@return void 
		-clear all frame
		-render objects
		-display frame in window

		Renders the game objects
	*/
	this->window->clear();


	//Draw player
	this->player.render_object(this->window);
	this->player.update_object(this->window);
	//Draw enemy
	
	this->enemy.render_object(this->window);


	this->window->display();
}
