#pragma once
#include "SFML/Graphics.hpp"
#include "Enemy_Bullet.h"
#include "Enemy.h"

using namespace sf;


class Animation_EnemyLip
{
public:

	/*
	* Ya que cada texture tiene 2 frames en 'x', y una solo fila, 'y' siempre es cero;
	* pero avanza en 'x' 16 pix;

	*/

	Animation_EnemyLip()
	{
		texture.loadFromFile("Assets\\Mini Pixel Pack 3\\Enemies\\Lips (16 x 16).png");
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
	static constexpr int nFrames = 5;
	static constexpr float holdTime = 0.08f;
	sf::Texture texture;
	sf::IntRect frames[nFrames];
	int iframe = 0;
	float time = 0.0f;
};

class Enemy_Lip {

public:
	Enemy_Lip(int hp, Vector2f pos);
	int hp;
	Texture texture;
	Sprite spr;
	Vector2f Pos;
	float Speed;
	bool enemyAlive;
	Retardos retardo;
	//Variable para balas
	float time_to_next_enemybullet;

	float frequencyBullet = 1.f;

	bool isAlive();
	void bajarHp(int daño);
	void moverPorImpacto(Retardos a);

	void Draw(RenderTarget& rt) const;
	void Update(float dt, Vector2f pos_nave);


	Vector2f getPosition() const {
		return spr.getPosition();
	}

private:

	Animation_EnemyLip animaciones;

	// Variables para manejar en el movimiento cuando lo golpea un disparo
	bool moviendo_impacto = false;
	float time_mover_impacto = 0.2f;

	// variable para que ignore la y en la posicion
	bool paso = false;

	// Objeto para determinar la animacion de explosion;
	Animation_Explosion animaciones_explosion;
};

