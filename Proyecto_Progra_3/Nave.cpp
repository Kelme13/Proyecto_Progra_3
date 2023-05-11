#include "Nave.h"
#include <iostream>



// Para la clase de animacion

Animation::Animation(int x, int y, int width, int height)
{
	textura.loadFromFile("Assets\\Mini Pixel Pack 3\\Player ship\\Player_ship.png");

	for (int i = 0; i < nFrames; i++)
	{
		frames[i] = { x + i * width, y, width, height };
	}

	iFrame = 2;

	time = 0.f;
}


void Animation::ApplyToSprite(Sprite& s) const
{
	s.setTexture(textura);
	s.setTextureRect(frames[iFrame]);
}

void Animation::Update(float dt)
{
	std::cout << "Dt: " << dt << std::endl;
	time += dt;
	while (time >= holdTime)
	{
		time -= holdTime;
		Advance();
	}
}

void Animation::Advance()
{
	if (++iFrame >= nFrames)
	{
		iFrame = 0;
	}
}




// Para la clase nave
Nave::Nave(Vector2f& pos_a) {

	textura = new Texture();
	textura->loadFromFile("Assets\\Mini Pixel Pack 3\\Player ship\\Player_ship.png");

	spr = new Sprite(*textura);
	spr->setScale(160.f / (float)spr->getTexture()->getSize().x, 80.f / (float)spr->getTexture()->getSize().y);
	spr->setTextureRect({ 16, 0, 16, 16 });

	vel = { 0.f, 0.f };
	pos = pos_a;
	
	for (int i = 0; i < 3; i++)
	{	
		frames[i] = { i * 16, 0, 16, 16 };

	}


	curAnimation = AnimationIndex::Non;
}

void Nave::SetDireccion(const Vector2f& dir)
{
	vel = dir * speed;
	if (dir.x > 0.f) {
		curAnimation = AnimationIndex::RighMov;
	}
	else if (dir.x < 0.f)
	{
		curAnimation = AnimationIndex::LeftMov;
	}
	else
	{
		curAnimation = AnimationIndex::Non;
	}
}

void Nave::Update(float dt)
{

	pos += vel * dt;
	spr->setTextureRect(frames[(int)curAnimation]);
	spr->setPosition(pos);
}


void Nave::Draw(RenderTarget& rt) const
{
	spr->setPosition(pos);
	rt.draw(*spr);
}
