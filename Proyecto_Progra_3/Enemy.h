#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
class Enemy {

public:
	Enemy(int hp, Vector2f pos);
	int hp;
	Texture texture;
	Sprite spr;
	Vector2f Pos;
	float Speed;
	bool enemyAlive;

	bool checkCollision(const sf::FloatRect& otherBounds) const;
	bool isAlive();
	void bajarHp(int daño);

	void Draw(RenderTarget& rt) const;
	void Update(float dt);

private:



};