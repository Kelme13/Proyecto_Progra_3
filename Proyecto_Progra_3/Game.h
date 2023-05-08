#pragma once
#include "SFML/Graphics.hpp"
#include "Nave.h"


using namespace sf;

class Game {
private:

	RenderWindow* Ventana;
	int fps = 60;

	// Nave
	Nave nave;

	Texture* tex_nave;
	Sprite* spr_nave;

	// NECESARIO Para manejar los eventos
	Event* eventos_1;

	// Vector para la direccion de la nave
	Vector2f dir;


public:
	Game(int ancho, int alto);
	void Dibujar();
	void Loop();

	void procesarEventosTeclado();



};