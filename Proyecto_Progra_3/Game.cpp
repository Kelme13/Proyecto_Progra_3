#include "Game.h"

using namespace std;


Game::Game() {
	 
	// Para la ventana
	

	Ventana = new RenderWindow(VideoMode(ancho, alto), "Space Shooter");

	Vector2f pos_centro = { Ventana->getSize().x / 2.f, Ventana->getSize().y - 100.f };

	nave = new Nave(pos_centro);
	BG = new Background("Assets\\Backgrounds\\Dynamic\\Nebula Blue.png", "Assets\\Backgrounds\\Dynamic\\EstrellaTipo1.png");

	// Todo para la nave

	eventos_1 = new Event();


	// timepoint for delta time measurement
	tp = std::chrono::steady_clock::now();

	// inicia el loop
	Loop();

}



int Game::GetAncho() {
	return ancho;
}

int Game::GetAlto() {
	return alto;
}



void Game::Loop(){


	while (Ventana->isOpen()) {
		
		
	
		procesarEventosTeclado();
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

	// handle input
	dir = { 0.f, 0.f };
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
				if (Keyboard::isKeyPressed(Keyboard::LShift)) {
					dir.x += 1.0f;
				}
				else {
					dir.x += 3.0f;
				}
				
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				if (Keyboard::isKeyPressed(Keyboard::LShift)) {
					dir.x -= 1.0f;
				}
				else {
					dir.x -= 3.0f;
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (Keyboard::isKeyPressed(Keyboard::LShift)) {
					dir.y -= 1.0f;
				}
				else {
					dir.y -= 3.0f;
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				if (Keyboard::isKeyPressed(Keyboard::LShift)) {
					dir.y += 1.0f;
				}
				else {
					dir.y += 3.0f;
				}
				
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
	
	if (Keyboard::isKeyPressed(Keyboard::LShift)) {
		nave->ShowHitbox(*Ventana);
	}


	Ventana->display();

}