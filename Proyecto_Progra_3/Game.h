#pragma once
#include "SFML/Graphics.hpp"
#include "Nave.h"
#include "Background.h"


using namespace sf;

class Game {
private:

	RenderWindow* Ventana;


	int fps = 60;


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