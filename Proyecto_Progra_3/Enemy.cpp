#include "Enemy.h"

Enemy::Enemy(int hp, Vector2f pos)
{
	this->hp = hp;
	texture.loadFromFile("Assets\\Mini Pixel Pack 3\\Enemies\\Alan.png");

	this->Pos = pos;
	enemyAlive = true;

	spr.setTexture(texture);
	spr.setPosition(pos);
	spr.setScale(3, 3);
	spr.setTextureRect({ 16, 0, 16, 16 });
}

bool Enemy::checkCollision(const sf::FloatRect& otherBounds) const
	{
		return spr.getGlobalBounds().intersects(otherBounds);
	}

bool Enemy::isAlive()
{
	return enemyAlive;
}

void Enemy::Draw(RenderTarget& rt) const
{
	rt.draw(spr);
}

void Enemy::bajarHp(int daño)
{
	hp -= daño;
}

void Enemy::Update(float dt)
{

	if (hp <= 0)
	{
		enemyAlive = false;
	}

	Speed = 20.f;
	spr.move(0.f, dt * Speed);
}
