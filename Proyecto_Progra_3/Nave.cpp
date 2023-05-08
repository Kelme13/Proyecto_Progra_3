#include "Nave.h"

Nave::Nave(RenderTarget& rt) {

	textura = new Texture();
	textura->loadFromFile("Assets\\Mini Pixel Pack 3\\Player ship\\Player_ship.png");

	spr = new Sprite(*textura);


	vel = { 0.f, 0.f };
	pos.x = rt.getSize().x / 2.f;
	pos.y = rt.getSize().y - 100.f;
	
}

void Nave::SetDireccion(const Vector2f& dir)
{
	vel = dir * speed;
}

void Nave::Update(float dt)
{
	pos += vel * dt;
}

void Nave::Draw(RenderTarget& rt) const
{
	rt.draw(*spr);
}

