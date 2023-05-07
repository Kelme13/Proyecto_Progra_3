#include "Game.h"



Game::Game(int ancho, int alto, std::string titulo) {

	fps = 60;

	Ventana = new RenderWindow(VideoMode(ancho, alto), titulo);
	textura1 = new Texture();
	sprite1 = new Sprite();

	textura1->loadFromFile("Assets\\Space Shooter\\Spritesheet\\sheet.png");
	sprite1->setTexture(*textura1);
	sprite1->setPosition(400, 300);

	Loop();
}


void Game::Loop(){

	while (Ventana->isOpen()) {
		Dibujar();

	}
}

void Game::Dibujar() {
	Ventana->clear();
	Ventana->draw(*sprite1);
	Ventana->display();

}