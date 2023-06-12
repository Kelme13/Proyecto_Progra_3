#include "Enemy_Bullet.h"



Enemy_Bullet::Enemy_Bullet(Vector2f pos_i)
{
	pos = pos_i;
	m_remaing_live = bulletEnemy_live_seconds;
	m_is_alive = true;
	spr.setPosition(pos);

	vel = { 0.f, 0.f };
	textura.loadFromFile("Assets\\Mini Pixel Pack 3\\Projectiles\\Player_beam (16 x 16).png");
	spr.setTexture(textura);
}

void Enemy_Bullet::Draw(RenderTarget& rt) const
{
	rt.draw(spr);
}

void Enemy_Bullet::Update(float dt)
{
	if (!m_is_alive) return;

	m_remaing_live -= dt;

	if (m_remaing_live < 0) m_is_alive = false;

	Vector2f tp = { 0.f, +1.f };
	vel = tp * bulletEnemy_speed;
	pos += vel * dt;

	animaciones.Update(dt);
	animaciones.ApplyToSprite(spr);

	spr.setPosition(pos);
	spr.setScale(80.f / (float)spr.getTexture()->getSize().x, 50.f / (float)spr.getTexture()->getSize().y);

	

}

bool Enemy_Bullet::isAlive()
{
	return m_is_alive;
}

Sprite Enemy_Bullet::getSprite()
{
	return this->spr;
}
