#include "Proyectil_beam.h"

Proyectil_beam::Proyectil_beam(Vector2f pos_i)
{
	pos = pos_i;
	m_remaing_live = bullet_live_seconds;
	m_is_alive = true;
	spr.setPosition(pos);

	vel = { 0.f, 0.f };
}

void Proyectil_beam::Draw(RenderTarget& rt) const
{
	rt.draw(spr);

}

void Proyectil_beam::Update(float dt)
{

	if (!m_is_alive) return;

	m_remaing_live -= dt;

	if (m_remaing_live < 0) m_is_alive = false;

	Vector2f tp = { 0.f, -1.f };
	vel =  tp * bullet_speed;
	pos += vel * dt;

	animaciones.Update(dt);
	animaciones.ApplyToSprite(spr);

	spr.setPosition(pos);
}

bool Proyectil_beam::isAlive()
{
	return m_is_alive;
}
