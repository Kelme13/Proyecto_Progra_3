#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
class Enemy {

public:

	int hp;
	Enemy(int hp);
	Texture texture;
	Sprite spr;
	Vector2f Pos;
	float Speed;


	bool checkCollision(const sf::FloatRect& otherBounds) const;


	void Draw(RenderTarget& rt) const;
	void Update(float dt);


private:



};