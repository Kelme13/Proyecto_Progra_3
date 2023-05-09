#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
class Background {

public:
	Background(const char* BackgroundFile);
	void Draw(sf::RenderTarget& rt) const;

private:
	sf::Texture* Textura;
	sf::Sprite* sprite;
	int ancho;
	int alto;


	
};


