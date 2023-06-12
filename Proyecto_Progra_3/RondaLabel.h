#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;



/*

	0 - pos 9
	1 - pos 0
	2 - pos 1
	3 - pos 2
	4 - pos 3
	5 - pos 4
	6 - pos 5
	7 - pos 6
	8 - pos 7
	9 - pos 9

*/

enum PosicionesNo
{
	Uno = 0,
	Dos = 1,
	Tres = 2,
	Cuatro = 3,
	Cinco = 4,
	Seis = 5,
	Siete = 6,
	Ocho = 7,
	Nueve = 8,
	Cero = 9
};



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


	void subirRonda(int ronda)
	{
		int u = 0, d = 0, c = 0;

		int cont = 0;

		while (ronda != 0)
		{
			int res = ronda % 10;

			if (cont == 0)
			{
				u = res;
			}
			else if (cont == 1)
			{
				d = res;
			}
			else if (cont == 2)
			{
				c = res;
			}

			++cont;
			ronda = ronda / 10;

		}

		
		switch (u)
		{
		case 0:
			und = PosicionesNo::Cero;
			break;

		case 1:
			und = PosicionesNo::Uno;
			break;

		case 2:
			und = PosicionesNo::Dos;
			break;

		case 3:
			und = PosicionesNo::Tres;
			break;

		case 4:
			und = PosicionesNo::Cuatro;
			break;

		case 5:
			und = PosicionesNo::Cinco;
			break;

		case 6:
			und = PosicionesNo::Seis;
			break;

		case 7:
			und = PosicionesNo::Siete;
			break;

		case 8:
			und = PosicionesNo::Ocho;
			break;

		case 9:
			und = PosicionesNo::Nueve;
			break;
		}

		
		switch (d)
		{
		case 0:
			dec = PosicionesNo::Cero;
			break;

		case 1:
			dec = PosicionesNo::Uno;
			break;

		case 2:
			dec = PosicionesNo::Dos;
			break;

		case 3:
			dec = PosicionesNo::Tres;
			break;
		case 4:
			dec = PosicionesNo::Cuatro;
			break;
		case 5:
			dec = PosicionesNo::Cinco;
			break;
		case 6:
			dec = PosicionesNo::Seis;
			break;
		case 7:
			dec = PosicionesNo::Siete;
			break;
		case 8:
			dec = PosicionesNo::Ocho;
			break;
		case 9:
			dec = PosicionesNo::Nueve;
			break;
		}

		switch (c)
		{
		case 0:
			cen = PosicionesNo::Cero;
			break;
		case 1:
			cen = PosicionesNo::Uno;
			break;
		case 2:
			cen = PosicionesNo::Dos;
			break;
		case 3:
			cen = PosicionesNo::Tres;
			break;
		case 4:
			cen = PosicionesNo::Cuatro;
			break;
		case 5:
			cen = PosicionesNo::Cinco;
			break;
		case 6:
			cen = PosicionesNo::Seis;
			break;
		case 7:
			cen = PosicionesNo::Siete;
			break;
		case 8:
			cen = PosicionesNo::Ocho;
			break;
		case 9:
			cen = PosicionesNo::Nueve;
			break;
		}

	}
	

	void draw(RenderTarget& rt) const
	{
		rt.draw(unidades[int(und)]);
		rt.draw(decimas[int(dec)]);
		rt.draw(centecimas[int(cen)]);
	}

private:
	Vector2f pos;
	Texture textura;
	Sprite unidades[10], decimas[10], centecimas[10];

	PosicionesNo und = PosicionesNo::Uno, dec = PosicionesNo::Cero, cen = PosicionesNo::Cero;

};
