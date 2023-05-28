#include "Proyectil_beam.h"

Proyectil_beam::Proyectil_beam(Vector2f pos_i)
{
	pos = pos_i;
	vel = { 0.f, 0.f };
}

void Proyectil_beam::Draw(RenderTarget& rt) const
{
	rt.draw(spr);

}

void Proyectil_beam::Update()
{


	Vector2f tp = { 0.f, -1.f };
	vel =  tp * speed;
	pos += vel * float(1/60);


	animaciones.Update(float(1 / 60));
	animaciones.ApplyToSprite(spr);

	spr.setPosition(pos);
}
