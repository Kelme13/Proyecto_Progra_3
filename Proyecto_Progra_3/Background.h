#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
class Background {

public:
	Background(const char* BackgroundFile, const char* EstrellaFile);
	void Draw(sf::RenderTarget& rt) const;
	void Estrellas(sf::RenderTarget& rt) const;

private:
	//Para el fondo
	sf::Texture* Textura;
	sf::Sprite* sprite;
	int ancho;
	int alto;
	

	//Para las estrellas
	sf::Texture* Estrella;
    sf::Sprite* Star;
	
};


