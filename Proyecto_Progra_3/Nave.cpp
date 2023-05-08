#include "Nave.h"

Nave::Nave(Vector2f& pos_a) {

	textura = new Texture();
	textura->loadFromFile("Assets\\Mini Pixel Pack 3\\Player ship\\Player_ship.png");

	spr = new Sprite(*textura);
	spr->setScale(160.f / (float)spr->getTexture()->getSize().x, 80.f / (float)spr->getTexture()->getSize().y);
	spr->setTextureRect({ 16, 0, 16, 16 });

	vel = { 0.f, 0.f };
	pos = pos_a;
	
}

void Nave::SetDireccion(const Vector2f& dir)
{
	vel = dir * speed;
}

void Nave::Update(float dt)
{
	pos += vel * dt;
	spr->setPosition(pos);
}

void Nave::Draw(RenderTarget& rt) const
{
	spr->setPosition(pos);
	rt.draw(*spr);
}

