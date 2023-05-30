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

void Enemy::moverPorImpacto()
{
	moviendo_impacto = true;
}

void Enemy::Update(float dt)
{

	if (hp <= 0)
	{
		enemyAlive = false;
	}

	animaciones.Update(dt);
	animaciones.ApplyToSprite(spr);

	Speed = 20.f;
	spr.setScale(40.f / (float)16.f, 40.f / 16.f);

	if (moviendo_impacto && time_mover_impacto > 0.f)
	{
		spr.move(0.f, dt * -(Speed + 50));
		time_mover_impacto -= dt;
	}
	else
	{
		moviendo_impacto = false;
		time_mover_impacto = 0.3f;
		spr.move(0.f, dt * Speed);
	}
}
