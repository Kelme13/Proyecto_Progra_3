#include "Nave.h"
#include <iostream>


class booster {
private:

		


};

// Para la clase nave
Nave::Nave(Vector2f& pos_a)
{

	textura = new Texture();
	textura->loadFromFile("Assets\\Mini Pixel Pack 3\\Player ship\\Player_ship.png");

	spr = new Sprite(*textura);
	spr->setScale(130.f / (float)spr->getTexture()->getSize().x, 50.f / (float)spr->getTexture()->getSize().y);
	spr->setTextureRect({ 16, 0, 16, 16 });
	spr->setPosition(pos_a);
	vel = { 0.f, 0.f };
	pos = pos_a;

	for (int i = 0; i < 3; i++)
	{
		movimientos[i] = { i * 16, 0, 16, 16 };
	}
	
	iFrame = 1;
}

void Nave::SetDireccion(const Vector2f& dir)
{
	vel = dir * speed;

	if (dir.x < 0.f)
	{
		iFrame = 0;
	}
	else if (dir.x > 0.f)
	{
		iFrame = 2;
	}
	else if (dir.x == 0)
	{
		iFrame = 1;
	}
}

void Nave::Update(float dt)
{
	spr->setTextureRect(movimientos[iFrame]);
	pos += vel * dt;
	std::cout<<  "x: " << pos.x << "y: " << pos.y << std::endl;
	spr->setPosition(pos);
}


void Nave::Draw(RenderTarget& rt) const
{
	rt.draw(*spr);
}

void Nave::Miniatura() {

	spr->setScale(100.f / (float)spr->getTexture()->getSize().x, 30.f / (float)spr->getTexture()->getSize().y);

}

void Nave::Normal()
{
	spr->setScale(130.f / (float)spr->getTexture()->getSize().x, 50.f / (float)spr->getTexture()->getSize().y);

}

