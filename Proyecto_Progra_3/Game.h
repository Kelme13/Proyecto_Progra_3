#pragma once
#include "SFML/Graphics.hpp"
#include <chrono>
#include "Nave.h"
#include "Background.h"


class Game {
private:

	RenderWindow* Ventana;


	//Como vamos a estar trabajando con bounds, entonces mejor tener un valor fijo de las ventanas para usarlos como referencias, hice unas funciones Get para esto.
	const int ancho = 800;
	const int alto = 900;


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
	

	// time point for delta time measure
	std::chrono::steady_clock::time_point tp;

public:
	Game();
	void Dibujar();
	void Loop();
	void Cerrar();
	void procesarEventosTeclado();

	//Funciones para el tamaño de la ventana
	int GetAncho();
	int GetAlto();

};