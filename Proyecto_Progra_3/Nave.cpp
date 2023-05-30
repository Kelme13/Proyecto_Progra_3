#include "Nave.h"
#include <iostream>


// Para la clase nave
Nave::Nave(Vector2f& pos_a)
{
	hitbox.setRadius(8);
	hitbox.setFillColor(Color::Red);

	// texturas para la nave
	textura = new Texture();
	textura->loadFromFile("Assets\\Mini Pixel Pack 3\\Player ship\\Player_ship.png");

	spr = new Sprite(*textura);
	spr->setScale(130.f / (float)spr->getTexture()->getSize().x, 50.f / (float)spr->getTexture()->getSize().y);
	spr->setTextureRect({ 16, 0, 16, 16 });
	spr->setPosition(pos_a);
	hitbox.setPosition({pos_a.x + 8, pos_a.y + 8});
	vel = { 0.f, 0.f };
	pos = pos_a;

	for (int i = 0; i < 3; i++)
	{
		movimientos[i] = { i * 16, 0, 16, 16 };
	}
	
	iFrame = 1;


	// texturas y spr para los booster

	animaciones[0] = Animation_Booster("Assets\\Mini Pixel Pack 3\\Player ship\\Boosters.png");
	animaciones[1] = Animation_Booster("Assets\\Mini Pixel Pack 3\\Player ship\\Boosters_right.png");
	animaciones[2] = Animation_Booster("Assets\\Mini Pixel Pack 3\\Player ship\\Boosters_left.png");

}

void Nave::SetDireccion(const Vector2f& dir)
{
	vel = dir * speed;

	if (dir.x < 0.f)
	{
		iFrame = 0;
		iFrame_booster = 2;
	}
	else if (dir.x > 0.f)
	{
		iFrame = 2;
		iFrame_booster = 1;
	}
	else if (dir.x == 0)
	{
		iFrame = 1;
		iFrame_booster = 0;
	}
}

void Nave::Update(float dt)
{
	spr->setTextureRect(movimientos[iFrame]);
	pos += vel * dt;

	// validaciones para que no se escape de la pantalla en x
	if (pos.x <= 4.f)
	{
		pos.x = 4.f;
	}
	else if (pos.x > 757.f)
	{
		pos.x = 757.f;
	}

	// validaciones para que no se escape de la pantalla en y

	if (pos.y <= 0.5f)
	{
		pos.y = 0.5f;
	}
	
	else if (pos.y >= 851.5f)
	{
		pos.y = 851.5f;
	}

	spr->setPosition(pos);
	animaciones[iFrame_booster].Update(dt);
	animaciones[iFrame_booster].ApplyToSprite(spr_booster);
	

	hitbox.setPosition({ pos.x + 14, pos.y + 18 });
}


void Nave::Draw(RenderTarget& rt) const
{	

	rt.draw(*spr);
	rt.draw(spr_booster);
}


void Nave::Miniatura() {

	spr->setScale(100.f / (float)spr->getTexture()->getSize().x, 40.f / (float)spr->getTexture()->getSize().y);
	spr_booster.setScale(100.f / (float)spr->getTexture()->getSize().x, 40.f / (float)spr->getTexture()->getSize().y);
	spr_booster.setPosition({ pos.x, pos.y + 36});
	
	speed = 300.f + 70.f;
}

void Nave::Normal()
{
	speed = 300.f;
	spr_booster.setScale(110.f / (float)spr->getTexture()->getSize().x, 50.f / (float)spr->getTexture()->getSize().y);
	spr_booster.setPosition({ pos.x, pos.y + 46 });
	spr->setScale(110.f / (float)spr->getTexture()->getSize().x, 50.f / (float)spr->getTexture()->getSize().y);
}

Vector2f Nave::getPos()
{
	return spr->getPosition();
}


void Nave::ShowHitbox(RenderTarget& rt) const {
	rt.draw(hitbox);
}


