#pragma once
#include "SFML/Graphics.hpp"
#include <chrono>

using namespace sf;


const float bulletEnemy_live_seconds = 2.0f;   //Vida maxima de una bala es segundos
const float bulletEnemy_speed = 400.0f;    //Velocidad de la bala en pixel / segundo
const float bulletEnemy_shoot_speed_seconds = 2.f; // Frecuencia de disparos
const float bulletEnemy_daño = 50.f;


class Animation_BulletEnemy
{
public:

	/*
	* Ya que cada texture tiene 2 frames en 'x', y una solo fila, 'y' siempre es cero;
	* pero avanza en 'x' 16 pix;

	*/

	Animation_BulletEnemy()
	{
		texture.loadFromFile("Assets\\Mini Pixel Pack 3\\Projectiles\\Enemy_projectile (16 x 16).png");
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
	static constexpr int nFrames = 2;
	static constexpr float holdTime = 0.08f;
	sf::Texture texture;
	sf::IntRect frames[nFrames];
	int iframe = 0;
	float time = 0.0f;
};



class Enemy_Bullet
{
public:

public:
	Enemy_Bullet(Vector2f pos_i);

	void Draw(RenderTarget& rt) const;
	void Update(float dt);
	bool isAlive();

	Sprite getSprite();

private:
	Vector2f pos;
	Vector2f vel;

	float m_remaing_live;
	bool m_is_alive;
	float shootTimer;

	sf::Texture textura;
	sf::Sprite spr;

	Animation_BulletEnemy animaciones;
};


