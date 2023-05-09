#include "Game.h"
#include "Boss.h"
#include <iostream>
#include <sstream>

void Game::initVariables()
{
	this->window = nullptr;
	//this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "The Game", sf::Style::Titlebar | sf::Style::Close );
	this->window->setFramerateLimit(60);
}
void Game::loadTexture()
{
	if (!this->background_texture.loadFromFile("Textures/spacefield_a-000.png"))
	{
		std::cout << "Error loading font" << std::endl;
	}
}



void Game::loadFont()
{
	if (!this->font.loadFromFile("Fonts/BAUHS93.ttf")) 
	{
		std::cout<<"Error loading font"<<std::endl;
	}
}

void Game::initBackground()
{
	this->space.setTexture(background_texture);
	this->space.setScale(sf::Vector2f(0.8f, 0.8f));
}

void Game::initText()
{
	//Points
	this->points_text.setFont(this->font);
	this->points_text.setCharacterSize(18);
	this->points_text.setFillColor(sf::Color::White);
	this->points_text.setOutlineColor(sf::Color::Black);
	this->points_text.setOutlineThickness(2);
	this->points_text.setPosition(sf::Vector2f(3.f, 0.f));

	//Health
	this->health_text.setFont(this->font);
	this->health_text.setCharacterSize(18);
	this->health_text.setFillColor(sf::Color::White);
	this->health_text.setOutlineColor(sf::Color::Black);
	this->health_text.setOutlineThickness(2);
	this->health_text.setPosition(sf::Vector2f(3.f, 20.f));

	//Game Over
	this->game_over_text.setFont(this->font);
	this->game_over_text.setCharacterSize(60);
	this->game_over_text.setFillColor(sf::Color::Red);
	this->game_over_text.setOutlineColor(sf::Color::Black);
	this->game_over_text.setOutlineThickness(2);
	this->game_over_text.setString("GAME OVER. PRESS ESC");
	this->game_over_text.setPosition(sf::Vector2f(100.f, 200.f));
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->loadTexture();
	this->initBackground();
	this->loadFont();
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

bool Game::endGame()
{
	if (player.health <= 0) {
		return true;
	}
	else
	{
		return false;
	}
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
	std::stringstream points_ss;
	std::stringstream health_ss;

	points_ss << "Points: " << this->player.points;
	this->points_text.setString(points_ss.str());

	health_ss << "Health: " << this->player.health;
	this->health_text.setString(health_ss.str());
}


//Functions
void Game::update()
{
	this->pollEvents();
	if(!endGame()){
		this->player.update_object(this->window);
		this->enemies.update_enemies(this->player, this->window, this->projectiles);
		this->projectiles.update_projectiles(this->player, this->window);
		this->updateGui();
	}
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->points_text);
	target->draw(this->health_text);
	if (endGame()) {
		target->draw(this->game_over_text);
	}
}

void Game::renderBackground(sf::RenderTarget* target)
{
	target->draw(this->space);
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

	//Draw Background
	this->renderBackground(this->window);
	//Draw player
	//this->player.update_object(this->window);
	this->player.render_object(this->window);
	//Draw enemy
	//this->enemies.update_enemies(this->player, this->window, this->projectiles);
	this->enemies.render_enemies(this->window);
	//Draw projectiles
	//this->projectiles.update_projectiles(this->player, this->window);
	this->projectiles.render_projectiles(this->window);
	//Render GUIinterface
	this->renderGui(this->window);
	


	this->window->display();
}
