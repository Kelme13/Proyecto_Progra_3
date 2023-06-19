#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

//Opciones del menu
//1. Jugar
//2. Opciones 
//3. Record
//4. Salir

#define OpcionesMenu 4
class MainMenu
{
public:

	MainMenu();
	void Draw(RenderWindow& rt);

	

	//Para verificar si el menu esta abierto en el main
	bool Abierto;
	int MainMenuSelected;

	//Para movimientos del menu
	void MoveUp();
	void MoveDown();

	~MainMenu();

	//Cerrar cuando se selecciona salir
	void Cerrar();

	//Texto 
	Font font;
	Text mainMenu[OpcionesMenu];

};

