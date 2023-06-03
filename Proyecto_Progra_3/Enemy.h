#pragma once
#include "SFML/Graphics.hpp"
#include "Enemy_Bullet.h"

using namespace sf;


// Enunciado para variar entre los retardos de las balas
enum class Retardos
{
	Normal = 25,
	Potente = 90
};

class Animation_Enemy
{
public:

	/*
	* Ya que cada texture tiene 2 frames en 'x', y una solo fila, 'y' siempre es cero;
	* pero avanza en 'x' 16 pix;

	*/

	Animation_Enemy()
	{
		texture.loadFromFile("Assets\\Mini Pixel Pack 3\\Enemies\\Alan.png");
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
	static constexpr int nFrames = 6;
	static constexpr float holdTime = 0.08f;
	sf::Texture texture;
	sf::IntRect frames[nFrames];
	int iframe = 0;
	float time = 0.0f;
};

class Animation_Explosion
{
public:

	/*
	* Ya que cada texture tiene 2 frames en 'x', y una solo fila, 'y' siempre es cero;
	* pero avanza en 'x' 16 pix;

	*/

	Animation_Explosion()
	{
		texture.loadFromFile("Assets\\Mini Pixel Pack 3\\Effects\\Explosion (16 x 16).png");
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

	// Funcion util mas adelante para que solamente se repita una vez la animacion
	bool esUltimoFrame()
	{
		return (iframe == nFrames - 1);
	}

private:
	void Advance()
	{
		if (++iframe >= nFrames)
		{
			iframe = 0;
		}
	}
	static constexpr int nFrames = 6;
	static constexpr float holdTime = 0.08f;
	sf::Texture texture;
	sf::IntRect frames[nFrames];
	int iframe = 0;
	float time = 0.0f;
};

class Enemy {

public:
	Enemy(int hp, Vector2f pos);
	int hp;
	Texture texture;
	Sprite spr;
	Vector2f Pos;
	float Speed;
	bool enemyAlive;
	Retardos retardo;
	void ShootBullet(Enemy_Bullet bull);


	bool isAlive();
	void bajarHp(int daño);
	void moverPorImpacto(Retardos a);

	void Draw(RenderTarget& rt) const;
	void Update(float dt);

private:

	Animation_Enemy animaciones;

	// Variables para manejar en el movimiento cuando lo golpea un disparo
	bool moviendo_impacto = false;
	float time_mover_impacto = 0.2f;

	// Objeto para determinar la animacion de explosion;
	Animation_Explosion animaciones_explosion;
};