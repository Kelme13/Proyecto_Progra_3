#include "SFML/Graphics.hpp"
#include "Proyectil_beam.h"
using namespace sf;

class Animation_ChargedBeam
{
public:

	/*
	* Ya que cada texture tiene 2 frames en 'x', y una solo fila, 'y' siempre es cero;
	* pero avanza en 'x' 16 pix;

	*/

	Animation_ChargedBeam()
	{
		texture.loadFromFile("Assets\\Mini Pixel Pack 3\\Projectiles\\Player_charged_beam (16 x 16).png");
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


const float beamCharged_live_seconds = 3.0f;   //Vida maxima de una bala es segundos
const float beamCharged_speed = 300.0f;    //Velocidad de la bala en pixel / segundo
const float beamCharged_shoot_speed_seconds = 0.4f; // Frecuencia de disparos
const int beamCharged_daño = 100;

class ProyectilChargedBeam
{
public:
	ProyectilChargedBeam(Vector2f pos_i);

	void Draw(RenderTarget& rt) const;
	void Update(float dt);

	sf::Sprite getSprite();
	bool isAlive();
	void kill();


	sf::FloatRect getBounds() const;

private:
	Vector2f pos;
	Vector2f vel;

	float m_remaing_live;
	bool m_is_alive;

	sf::Texture textura;
	sf::Sprite spr;

	Animation_ChargedBeam animaciones;
};

