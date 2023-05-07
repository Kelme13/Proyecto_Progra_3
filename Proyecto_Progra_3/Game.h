#pragma once
#include "SFML/Graphics.hpp"


using namespace sf;
class Game {

public:
	Game(int ancho, int alto, std::string titulo);
	void Dibujar();
	void Loop();

private: 
	RenderWindow * Ventana;
	int fps = 60;
	Texture* textura1;
	Sprite* sprite1;
};