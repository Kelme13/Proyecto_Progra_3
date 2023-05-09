#include "Game.h"

using namespace std;


Game::Game(int ancho, int alto) {
	 
	// Para la ventana

	fps = 60;

	Ventana = new RenderWindow(VideoMode(ancho, alto), "titulo");

	Vector2f pos_centro = { Ventana->getSize().x / 2.f, Ventana->getSize().y - 100.f };

	nave = new Nave(pos_centro);
	BG = new Background("Assets\\Backgrounds\\SpaceMoving.gif");

	// Todo para la nave

	int x, y, dx, dy;

	int indiceX, indiceY;

	tex_nave = new Texture();
	spr_nave = new Sprite();

	tex_nave->loadFromFile("Assets\\Mini Pixel Pack 3\\Player ship\\Player_ship.png");

	spr_nave->setTexture(*tex_nave);
	spr_nave->setPosition(Ventana->getSize().x / 2.f, Ventana->getSize().y - 100.f);
	spr_nave->setTextureRect({ 16,0,16,16 });
	
	eventos_1 = new Event();


	// timepoint for delta time measurement
	tp = std::chrono::steady_clock::now();


	Loop();
}


void Game::Loop(){


	while (Ventana->isOpen()) {
		
		//dir = { 0.f, 0.f };

		
		//procesarEventosTeclado();
		Cerrar();
		Dibujar();
		 
	}
}


void Game::Cerrar() {
	sf::Event event;
	while (Ventana->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			Ventana->close();
		}
	}
}

void Game::procesarEventosTeclado()
{
	

	// get dt
	float dt;
	{
		const auto new_tp = std::chrono::steady_clock::now();
		dt = std::chrono::duration<float>(new_tp - tp).count();
		tp = new_tp;
	}

	

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

			nave->SetDireccion(dir);

			// update model
			nave->Update(dt);


			break;

		}



	}

}

void Game::Dibujar() {
	Ventana->clear();
	BG->Draw(*Ventana);
	nave->Draw(*Ventana);
	
	Ventana->display();

}