#pragma once
#include "GameObject.h"
#include <vector>
class Player : public GameObject
{
private:
	sf::RectangleShape p_shape;
	sf::Texture player_texture;
	sf::Sprite starship;

	void init_shape() override;

public:
	Player();
	int points;
	void spawn_object();
	void update_window_bounce_collision(const sf::RenderTarget* target);
	void update_object(const sf::RenderTarget* target);
	void render_object(sf::RenderTarget* target) override;
	void move_object() override;
	const sf::Sprite& get_shape() const;
	void load_texture();

};
