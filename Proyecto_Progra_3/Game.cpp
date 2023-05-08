#include "Game.h"
#include "Nave.h"

enum Direcciones{Niguna, Izquierda, Derecha};

Game::Game(int ancho, int alto, std::string titulo) {
	 
	// Para la ventana

	fps = 60;

	Ventana = new RenderWindow(VideoMode(ancho, alto), titulo);



	Nave* nave = new Nave(*Ventana);




	// Todo para la nave

	int x, y, dx, dy;

	int indiceX, indiceY;

	Direcciones direccion = Niguna;

	tex_nave = new Texture();
	spr_nave = new Sprite();

	tex_nave->loadFromFile("Assets\\Mini Pixel Pack 3\\Player ship\\Player_ship.png");

	spr_nave->setTexture(*tex_nave);
	spr_nave->setPosition(Ventana->getSize().x / 2.f, Ventana->getSize().y - 100.f);
	spr_nave->setTextureRect({ 16,0,16,16 });
	


	Loop();
}


void Game::Loop(){

	while (Ventana->isOpen()) {
		
		dir = { 0.f, 0.f };

		procesarEventosTeclado();

		Dibujar();
		 
	}
}

void Game::procesarEventosTeclado()
{
	while (Ventana->pollEvent(*eventos_1)) {

		switch (eventos_1->type)
		{
		case Event::Closed:
			Ventana->close();
			exit(1);
			break;

		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::A)) {
				exit(0);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				dir.x += 1.f; 
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				dir.x -= 1.f;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				dir.y -= 1.f;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				dir.y += 1.f;
			}
			break;

		}



	}

}

void Game::Dibujar() {
	Ventana->clear();
	
	nave->Draw(*Ventana);

	Ventana->display();

}