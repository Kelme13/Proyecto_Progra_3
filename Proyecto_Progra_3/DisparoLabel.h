#include "SFML/Graphics.hpp"

using namespace sf;
class DisparoLabel
{
public:
	DisparoLabel()
	{
		pos = { 790.f, 90.f };

		texturas[0].loadFromFile("Assets\\Mini Pixel Pack 3\\Projectiles\\Player_beam (16 x 16).png");
		texturas[1].loadFromFile("Assets\\Mini Pixel Pack 3\\Projectiles\\Player_charged_beam (16 x 16).png");

		rect = { 8, 0, 8, 16 };

		actualTextura = 0;
		spr.setTexture(texturas[0]);
		spr.setTextureRect(rect);
		spr.setPosition(pos);
		spr.setRotation(90.f);
		spr.setScale(50.f / (float)spr.getTexture()->getSize().x, 50.f / (float)spr.getTexture()->getSize().y);
	}

	void cambiarDisparo()
	{
		if (actualTextura == 0)
		{
			spr.setTexture(texturas[1]);
			actualTextura = 1;
		}
		else
		{
			spr.setTexture(texturas[0]);
			actualTextura = 0;
		}
	}

	void draw(RenderTarget& rt) const
	{
		rt.draw(spr);
	}

private:
	Vector2f pos;
	Texture texturas[2];
	IntRect rect;
	Sprite spr;
	int actualTextura;


};
