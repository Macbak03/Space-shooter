#pragma once
#include "GameObject.h"
class Enemy : public GameObject
{
private:
	sf::RectangleShape e_shape;
	float x, y;
	const int max_enemy_ammount;
	int enemy_ammount;
	void initShape();
public:
	Enemy();
	virtual ~Enemy();
	void update_object(const sf::RenderTarget* target) override;
	void render_object(sf::RenderTarget* target) override;
	void move_object() override;
	void spawn_object() override;
};
