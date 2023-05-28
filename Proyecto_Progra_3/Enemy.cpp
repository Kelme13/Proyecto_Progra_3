#include "Enemy.h"

Enemy::Enemy(int hp)
{
	this->hp = hp;
	texture.loadFromFile("Assets\\Mini Pixel Pack 3\\Enemies\\Alan.png");
	spr.setTexture(texture);
	spr.setPosition(1000.f, 1000.f);
}

bool Enemy::checkCollision(const sf::FloatRect& otherBounds) const
	{
		return spr.getGlobalBounds().intersects(otherBounds);
	}


void Enemy::Draw(RenderTarget& rt) const
{
	rt.draw(spr);
}

void Enemy::Update(float dt)
{

	Speed = 20.f;
	spr.move(0.f, dt * Speed);
}
