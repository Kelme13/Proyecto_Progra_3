#include "Nave.h"
// Para la clase nave
Nave::Nave(Vector2f& pos_a) {

	textura = new Texture();
	textura->loadFromFile("Assets\\Mini Pixel Pack 3\\Player ship\\Player_ship.png");

	spr = new Sprite(*textura);
	spr->setScale(160.f / (float)spr->getTexture()->getSize().x, 80.f / (float)spr->getTexture()->getSize().y);
	spr->setTextureRect({ 16, 0, 16, 16 });

	vel = { 0.f, 0.f };
	pos = pos_a;

	animations[int(AnimationIndex::LeftMov)] = new Animation(0, 0, 16, 16);
	animations[int(AnimationIndex::Non)] = new Animation(16, 0, 16, 16);
	animations[int(AnimationIndex::LeftMov)] = new Animation(32, 0, 16, 16);
	
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

	animations[int( curAnimation)]->Update(dt);
	animations[int(curAnimation)]->ApplyToSprite(*spr);
	 
	spr->setPosition(pos);
}


void Nave::Draw(RenderTarget& rt) const
{
	spr->setPosition(pos);
	rt.draw(*spr);
}


// Para la clase de animacion

Animation::Animation(int x, int y, int width, int height)
{
	textura.loadFromFile("Assets\\Mini Pixel Pack 3\\Player ship\\Player_ship.png");

	for (int i = 0; i < nFrames; i++)
	{
		frames[i] = { x + i * width, y, width, height };
	}
}


void Animation::ApplyToSprite(Sprite& s) const
{
	s.setTexture(textura);
	s.setTextureRect(frames[iFrame]);
}

void Animation::Update(float dt)
{
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
