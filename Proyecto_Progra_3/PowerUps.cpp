#include "PowerUps.h"

PowerUps::PowerUps(typePower p)
{
	this->power = p;
	powerItem.loadFromFile("Assets\\Mini Pixel Pack 3\\Items\\Power_item (16 x 16).png");
	spr.setTexture(powerItem);

	if (int(p) == 1) rect = { 0, 0 , 16, 16 };

	if (int(p) == 0) rect = { 16, 0 , 16, 16 };

	if (int(p) == 3) rect = { 32, 0 , 16, 16 };


	spr.setTextureRect(rect);
	// Voy a generar un random en x
	int x = std::rand() % 3;

	pos = {float(x * 200) + 30.f, -50.f};
	vel = { 0.f, 0.f };
}

void PowerUps::draw(RenderTarget& rt) const
{
	rt.draw(spr);
}

void PowerUps::update(float dt)
{

	Vector2f tp = { 0.f, +1.f };
	vel = tp * 300.f;
	pos += vel * dt;

	spr.setPosition(pos);
	spr.setScale(30.f / 16.f, 30.f / 16.f);

	time_power -= dt;
}

void PowerUps::activarPower(float t)
{
	this->time_power = t;
}

void PowerUps::noMostrar()
{
	this->mostrar = false;
}

Sprite PowerUps::getSprite()
{
	return this->spr;
}

typePower PowerUps::getTipo()
{
	return this->power;
}

bool PowerUps::isMostrar()
{
	return this->mostrar;
}

bool PowerUps::isActivo()
{
	return this->time_power > 0.f;
;}
