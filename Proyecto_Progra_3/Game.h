#pragma once
#include "SFML/Graphics.hpp"
#include <chrono>
#include "Nave.h"
#include "Background.h"


class Game {
private:

	RenderWindow* Ventana;
	int fps = 60;

	// Nave
	Nave* nave;

	//Fondo
	Background* BG;

	Texture* tex_nave;
	Sprite* spr_nave;

	// NECESARIO Para manejar los eventos
	Event* eventos_1;

	// Vector para la direccion de la nave
	Vector2f dir;
	
	std::chrono::steady_clock::time_point tp;

public:
	Game(int ancho, int alto);
	void Dibujar();
	void Loop();
	void Cerrar();
	void procesarEventosTeclado();



};