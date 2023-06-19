#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class PowerupsLabel
{
public:
	PowerupsLabel()
	{
		pos = { 750.f, 108.f };

		textura.loadFromFile("Assets\\Mini Pixel Pack 3\\Items\\Power_item (16 x 16).png");

		rect_mostrar = { 0, 0, 16, 16 };
		rect_ocultar = { 16, 0, 16, 16 };

		for (int i = 0; i < 3; i++)
		{
			power[i].setTexture(textura);
			power[i].setPosition({ pos.x + (i * 20) , pos.y });
			power[i].setTextureRect({i* 16, 16, 16, 16});
			power[i].setScale(45.f / 16.f, 45.f / 16.f);
		}
	}


	void mostrarDano()
	{
		power[0].setTextureRect({0, 0, 16, 16});
	}
	void ocultarDano()
	{
		power[0].setTextureRect({0, 16, 16, 16});
	}


	void draw(RenderTarget& rt) const
	{
		for (int i = 0; i < 3; i++)
		{
			rt.draw(power[i]);

		}
	}

private:
	Vector2f pos;
	Texture textura;

	IntRect rect_mostrar, rect_ocultar;
	Sprite power[3];
};


