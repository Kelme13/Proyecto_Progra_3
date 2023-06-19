#include "ProyectilChargedBeam.h"

ProyectilChargedBeam::ProyectilChargedBeam(Vector2f pos_i)
{
	pos = pos_i;
	m_remaing_live = beamCharged_live_seconds;
	m_is_alive = true;
	spr.setPosition(pos);

	vel = { 0.f, 0.f };
	textura.loadFromFile("Assets\\Mini Pixel Pack 3\\Projectiles\\Player_beam (16 x 16).png");
	spr.setTexture(textura);
}

void ProyectilChargedBeam::Draw(RenderTarget& rt) const
{
	rt.draw(spr);
}

void ProyectilChargedBeam::Update(float dt, bool maximo)
{
	if (!m_is_alive) return;

	m_remaing_live -= dt;

	if (m_remaing_live < 0) m_is_alive = false;

	Vector2f tp = { 0.f, -1.f };
	vel = tp * beamCharged_speed;
	pos += vel * dt;

	animaciones.Update(dt);
	animaciones.ApplyToSprite(spr);

	spr.setPosition(pos);

	if(maximo)
		spr.setScale(60.f / (float)spr.getTexture()->getSize().x, 60.f / (float)spr.getTexture()->getSize().y);
	else
	{
		spr.setScale(50.f / (float)spr.getTexture()->getSize().x, 50.f / (float)spr.getTexture()->getSize().y);
	}

}

sf::Sprite ProyectilChargedBeam::getSprite()
{
	return this->spr;
}

bool ProyectilChargedBeam::isAlive()
{
	return m_is_alive;
}

void ProyectilChargedBeam::kill()
{
	m_is_alive = false;	
}
