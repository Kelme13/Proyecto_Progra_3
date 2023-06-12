#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class RondaLabel
{
public:
	RondaLabel()
	{

		textura.loadFromFile("Assets\\Mini Pixel Pack 3\\UI objects\\Number_font (8 x 8).png");

		rect_mostrar = { 0, 0, 8, 8 };

		for (int i = 0; i < 10; i++)
		{
			decimas[i].setTexture(textura);
			unidades[i].setTexture(textura);
			centecimas[i].setTexture(textura);

			if (i < 5)
			{
				decimas[i].setTextureRect({ 8 * i, 0, 8, 8 });
				unidades[i].setTextureRect({ 8 * i, 0, 8, 8 });
				centecimas[i].setTextureRect({ 8 * i, 0, 8, 8 });
				
			}
			else
			{
				decimas[i].setTextureRect({ 8 * (i-5), 8, 8, 8 });
				unidades[i].setTextureRect({ 8 * (i - 5), 8, 8, 8 });
				centecimas[i].setTextureRect({ 8 * (i - 5), 8, 8, 8 });
			}
			/*
			decimas[i].setScale(45.f / 8.f, 45.f / 8.f);
			unidades[i].setScale(45.f / 8.f, 45.f / 8.f);
			centecimas[i].setScale(45.f / 8.f, 45.f / 8.f);
			*/

			unidades[i].setPosition({ 750.f, 50.f });
			decimas[i].setPosition({ 700.f, 50.f });
			centecimas[i].setPosition({ 650.f, 50.f });

		}


	}


	

	void draw(RenderTarget& rt) const
	{
		rt.draw(unidades[0]);
		rt.draw(decimas[0]);
		rt.draw(centecimas[0]);
	}

private:
	Vector2f pos;
	Texture textura;
	IntRect rect_mostrar;
	Sprite unidades[10], decimas[10], centecimas[10];

	int und = 0, dec = 0, cen = 0;


};
