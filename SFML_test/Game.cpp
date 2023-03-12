#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include <iostream>
#include <sstream>

void Game::initVariables()
{
	this->window = nullptr;
	this->endGame = false;
	this->points = 0;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "The Game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}
void Game::initFont()
{
	if (!this->font.loadFromFile("Fonts/BAUHS93.ttf")) 
	{
		std::cout<<"Error loading font"<<std::endl;
	}
}

void Game::initText()
{
	this->text.setFont(this->font);
	this->text.setCharacterSize(18);
	this->text.setFillColor(sf::Color::White);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setOutlineThickness(2);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFont();
	this->initText();
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

void Game::updateGui()
{
	std::stringstream ss;

	ss << "Points: " << this->points;

	this->text.setString(ss.str());
}

//Functions
void Game::update()
{
	this->pollEvents();
	this->player.update_object(this->window);
	this->enemy.update_object(this->window, player);
	this->updateGui();
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->text);
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
	this->enemy.update_object(this->window, player);
	//Render GUIinterface
	this->renderGui(this->window);
	


	this->window->display();
}
