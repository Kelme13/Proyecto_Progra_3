#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class VidasLabel
{
public:
	VidasLabel()
	{
		pos = { 610.f, 5.f };

		textura.loadFromFile("Assets\\Mini Pixel Pack 3\\UI objects\\Player_life_icon (16 x 16).png");

		rect_mostrar = { 0, 0, 16, 16 };
		rect_ocultar = { 16, 0, 16, 16 };

		for (int i = 0; i < 5; i++)
		{
			vidas[i].setTexture(textura);
			vidas[i].setTextureRect(rect_mostrar);
			vidas[i].setPosition({pos.x + (i*35), pos.y});
			vidas[i].setScale(45.f / (float)textura.getSize().x, 45.f / (float)textura.getSize().y);

		}
	}


	void resetearVidas()
	{
		for (int i = 0; i < 5; i++)
		{
			vidas[i].setTextureRect(rect_mostrar);
			
		}
	}

	void actualizarVidas(int n_vidas)
	{
		for (int i = 4; i >= 0 ; i--)
		{
			if (--n_vidas < 0)
				vidas[i].setTextureRect(rect_ocultar);
		}
	}

	void draw(RenderTarget& rt) const
	{
		for (int i = 0; i < 5; i++)
		{
			rt.draw(vidas[i]);

		}
	}

private:
	Vector2f pos;
	Texture textura;
	IntRect rect_mostrar, rect_ocultar;
	Sprite vidas[5];
};
