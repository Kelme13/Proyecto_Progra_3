#pragma once
#include "SFML/Graphics.hpp"
#include "Enemy_Bullet.h"
#include "Enemy.h"
#include <list>
#include<cstdlib>
using namespace sf;
using namespace std;

class Animation_Boss
{
public:

	/*
	* Ya que cada texture tiene 2 frames en 'x', y una solo fila, 'y' siempre es cero;
	* pero avanza en 'x' 16 pix;

	*/

	Animation_Boss()
	{
		texture.loadFromFile("Assets\\Mini Pixel Pack 3\\Enemies\\Bon_Bon (16 x 16).png");
		for (int i = 0; i < nFrames; i++)
		{
			frames[i] = { 16 * i, 0, 16, 16 };
		}
	}

	void ApplyToSprite(Sprite& s) const
	{
		s.setTexture(texture);
		s.setTextureRect(frames[iframe]);
	}


	void Update(float dt)
	{
		time += dt;

		while (time >= holdTime)
		{
			time -= holdTime;
			Advance();
		}
	}

private:
	void Advance()
	{
		if (++iframe >= nFrames)
		{
			iframe = 0;
		}
	}
	static constexpr int nFrames = 4;
	static constexpr float holdTime = 0.08f;
	sf::Texture texture;
	sf::IntRect frames[nFrames];
	int iframe = 0;
	float time = 0.0f;
};




class Boss 
{

public:
	//Atributos
	float Speed = 25.f;


	int HP;
	int MaxHP;
	int BarrasVida;
	bool BossAlive;
	Texture texture;
	Sprite spr;
	Vector2f Pos;

	Boss(int hp, int barras, Vector2f pos);
	//Variable para balas
	float time_to_next_bossBullet = 0.0f;
	const float frequencyBulletBoss = 0.5f;

	float time_fase = 5.f;

	bool Aparecer(float dt);
	bool isAlive();
	void bajarHp(int daño);
	void Draw(RenderTarget& rt) const;
	void Update(float dt);

	void Shoot( list<Enemy_Bullet*>& EnemyBulletList);

	Vector2f getPosition() const {
		return spr.getPosition();
	}

private:
	Animation_Boss animation;
	Animation_Explosion animaciones_explosion;

	
	int faseActual = 1;

};

