#pragma once
#include "GameObject.h"
class Player : public GameObject
{
private:
	sf::RectangleShape p_shape;
	float x, y;
	void initShape();

public:
	Player();
	virtual ~Player();
	void spawn_object();
	void update_window_bounce_collision(const sf::RenderTarget* target);
	void update_object(const sf::RenderTarget* target);
	void render_object(sf::RenderTarget* target) override;
	void move_object() override;
	float get_player_y_position();
	float get_player_x_position();
};
