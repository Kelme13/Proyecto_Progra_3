#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>


const float time_DanoMaximo = 5.f;


//	Creamos un enunciado que determinara el tipo que es, para tenerlo todos agrupado

using namespace sf;
enum class typePower
{
	SaludMaxima,
	DanoMaximo,


	DisparoEstrella,
	Bomba
};


class PowerUps
{
	typePower power;
	sf::Texture powerItem;
	sf::Sprite spr;
	IntRect rect;


	Vector2f pos;
	Vector2f vel;

	float time_power = 0.f;

	bool mostrar = true;

public:
	PowerUps(typePower p);

	void draw(RenderTarget& rt) const;
	void update(float dt);
	void activarPower(float t);

	void noMostrar();

	Sprite getSprite();
	typePower getTipo();

	bool isMostrar();

	bool isActivo();
	
};

