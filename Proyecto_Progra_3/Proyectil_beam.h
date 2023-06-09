#pragma once
#include "SFML/Graphics.hpp"
#include <chrono>

using namespace sf;


const float bullet_live_seconds = 2.0f;   //Vida maxima de una bala es segundos
const float bullet_speed = 500.0f;    //Velocidad de la bala en pixel / segundo
const float bullet_shoot_speed_seconds = 0.2f; // Frecuencia de disparos
const float bullet_da�o = 50.f;


class Animation_Beam
{
public:

	/*
	* Ya que cada texture tiene 2 frames en 'x', y una solo fila, 'y' siempre es cero;
	* pero avanza en 'x' 16 pix;

	*/

	Animation_Beam()
	{
		texture.loadFromFile("Assets\\Mini Pixel Pack 3\\Projectiles\\Player_beam (16 x 16).png");
		for (int i = 0; i < nFrames; i++)
		{
			frames[i] = { 8 * i, 0, 8, 16 };
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


class Proyectil_beam
{
public:

	Proyectil_beam(Vector2f pos_i);

	void Draw(RenderTarget& rt) const;
	void Update(float dt, bool maximo);

	bool isAlive();
	void kill();
	sf::Sprite getSprite();

private:
	Vector2f pos;
	Vector2f vel;

	float m_remaing_live;
	bool m_is_alive;

	sf::Texture textura;
	sf::Sprite spr;


};

