#include "Proyectil_beam.h"

Proyectil_beam::Proyectil_beam(Vector2f pos_i)
{
	pos = pos_i;
	m_remaing_live = bullet_live_seconds;
	m_is_alive = true;
	spr.setPosition(pos);

	vel = { 0.f, 0.f };
	textura.loadFromFile("Assets\\Mini Pixel Pack 3\\Projectiles\\Player_beam (16 x 16).png");
	spr.setTexture(textura);
}

void Proyectil_beam::Draw(RenderTarget& rt) const
{
	rt.draw(spr);

}

void Proyectil_beam::Update(float dt, bool maximo)
{

	if (!m_is_alive) return;

	m_remaing_live -= dt;

	if (m_remaing_live < 0) m_is_alive = false;

	Vector2f tp = { 0.f, -1.f };
	vel =  tp * bullet_speed;
	pos += vel * dt;

	spr.setPosition(pos);

	if (maximo) spr.setScale(40.f / (float)spr.getTexture()->getSize().x, 40.f / (float)spr.getTexture()->getSize().y);
	else
	{
		spr.setScale(30.f / (float)spr.getTexture()->getSize().x, 30.f / (float)spr.getTexture()->getSize().y);
	}
	
}


bool Proyectil_beam::isAlive()
{
	return m_is_alive;
}

void Proyectil_beam::kill()
{
	m_is_alive = false;
}

sf::Sprite Proyectil_beam::getSprite()
{
	return this->spr;
}
