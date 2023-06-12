#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class RondaLabel
{
public:
	RondaLabel()
	{

		textura.loadFromFile("Assets\\Mini Pixel Pack 3\\UI objects\\Number_font (8 x 8).png");

		for (int i = 0; i < 10; i++)
		{
			decimas[i].setTexture(textura);
			unidades[i].setTexture(textura);
			centecimas[i].setTexture(textura);

			if (i < 5)
			{
				decimas[i].setTextureRect(IntRect{ 8 * i, 0, 8, 8 });
				unidades[i].setTextureRect(IntRect{ 8 * i, 0, 8, 8 });
				centecimas[i].setTextureRect(IntRect{ 8 * i, 0, 8, 8 });
				
			}
			else
			{
				decimas[i].setTextureRect(IntRect{ 8 * (i-5), 8, 8, 8 });
				unidades[i].setTextureRect(IntRect{ 8 * (i - 5), 8, 8, 8 });
				centecimas[i].setTextureRect(IntRect{ 8 * (i - 5), 8, 8, 8 });
			}
			
			decimas[i].setScale(30.f / 8.f, 30.f / 8.f);
			unidades[i].setScale(30.f / 8.f, 30.f / 8.f);
			centecimas[i].setScale(30.f / 8.f, 30.f / 8.f);
			

			unidades[i].setPosition({ 760.f, 50.f });
			decimas[i].setPosition({ 735.f, 50.f });
			centecimas[i].setPosition({ 710.f, 50.f });

		}


	}


	

	void draw(RenderTarget& rt) const
	{
		rt.draw(unidades[und]);
		rt.draw(decimas[dec]);
		rt.draw(centecimas[cen]);
	}

private:
	Vector2f pos;
	Texture textura;
	Sprite unidades[10], decimas[10], centecimas[10];

	int und = 9, dec = 9, cen = 9;


};
