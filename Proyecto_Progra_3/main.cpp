#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include <stdlib.h>

#include <list>
#include "Collision.h"

#include "Nave.h"
#include "Background.h"
#include "Proyectil_beam.h"
#include "Game.h"
#include "ProyectilChargedBeam.h"
#include "Enemy_Bullet.h"
#include"Enemy.h"

#include "DisparoLabel.h"
#include "VidasLabel.h"
#include "RondaLabel.h"

using namespace std;
using namespace sf;


//A (beams)- Definiciones para mejor comprension del codigo
typedef list<Proyectil_beam*> BeamList;
typedef list<Proyectil_beam*>::iterator BeamIndex;

//B (beams Charged)- Definiciones para mejor comprension del codigo
typedef list<ProyectilChargedBeam*> ChargedBeamList;
typedef list<ProyectilChargedBeam*>::iterator ChargedBeamIndex;

//D (Disparos de los enemigo) - 
typedef list<Enemy_Bullet*> EnemyBulletList;
typedef list<Enemy_Bullet*>::iterator EnemyBulletIndex;

//C (Aqui deberias tener una tbm para los enemigos que se muestran en pantalla)
typedef list<Enemy*> EnemyList;
typedef list<Enemy*>::iterator EnemyIndex;


enum class Disparos
{
	Beam,
	Charged_Beam
};


void generarEnemigos(list<Enemy*>& enemigos, int n)
{
	
	Vector2f pos;
	int cont_x = 0;
	int cont_y = 1;
	for (int i = 0; i < n; i++)
	{

		if (cont_x * 50 > 800)
		{
			cont_x = 0;
			cont_y++;

		}
		pos = { float(cont_x*40) + float(rand() % 4 * 15) , -200.f - float((rand() % 4) * 20) - float(cont_y * 80)};
		cont_x++;

		Enemy* enem = new Enemy(50, pos);
		enemigos.push_back(enem);
	}
	

}

bool hayEnemigos(list<Enemy*>& enemigos)
{
	EnemyIndex I = enemigos.begin();
	EnemyIndex E = enemigos.end();


	while (I != E)
	{
		Enemy* enem = (*I);
		if (enem->isAlive()) return true;
	}

	return false;
}

void generarBalasEnemigas(Enemy& enemy, EnemyBulletList& enemyBullets)
{

	// Posicion del enemigo
	sf::Vector2f position = {enemy.getPosition().x+14.f, enemy.getPosition().y};

	// Genera la bala
	Enemy_Bullet* bullet = new Enemy_Bullet(position);
	enemyBullets.push_back(bullet);

}

// PARAMETROS DURANTE EL JUEGO

int RONDA = 0;
int N_ENEMIGOS = 10;

int PUNTAJE = 0;
int VIDAS = 5;
// VARIABLES DE TIEMPO DURANTE EL JUEGO en segundos;

float time_to_next_level = 5.0f;

// Constantes para manejar algunas variantes con el tiempo
float time_to_next_bullet = 0.0f;	//A - Control de la fracuencia de disparo beam normal
float time_to_next_bullet_charged = 0.0f;
float time_to_cambiar_disparo = 0.0f; // espera ciertos milisegundo para cambiar entre los disparos
float time_to_restar_vida = 0.0f; // Espacio de tiempo para restarle la vida

void subirRonda()
{
	RONDA += 1;
	N_ENEMIGOS += 5;
}

int main() {

	//Game* juego = new Game();

	Disparos actualDisparo = Disparos::Beam;
	DisparoLabel disparoLabel;
	VidasLabel vidasLabel;
	RondaLabel rondaLabel;


	sf::RenderWindow window(sf::VideoMode(800, 900), "SpaceShooter - P3");
	// Load a sprite to display

	Vector2f pos_centro = { window.getSize().x / 2.f, window.getSize().y - 100.f };

	Nave* nave = new Nave(pos_centro);


	Background* BG = new Background("Assets\\Backgrounds\\Dynamic\\Nebula Blue.png", "Assets\\Backgrounds\\Dynamic\\EstrellaTipo4.png");

	// timepoint for delta time measurment
	std::chrono::steady_clock::time_point tp = std::chrono::steady_clock::now();

	//A - Contenedor de todas las balas disparadas
	BeamList beams;

	//B - Contenedor de todas las balas Cargadas
	ChargedBeamList chargedBeams;

	//C - Contenedor de todos los enemigos
	EnemyList enemigos;

	//D - Contenedor de las balas de los enemigos
	EnemyBulletList balasEnemigas;

	// Start the game loop
	while (window.isOpen())
	{

		if (!hayEnemigos(enemigos))
		{
			subirRonda();
			generarEnemigos(enemigos, N_ENEMIGOS);
			rondaLabel.subirRonda(RONDA);
		}

		/*
		* Vamos aqui vamos a comprobar las colisiones antes de todo
		*/

		// Recorre todos los enemigos
		EnemyIndex I_Enemy = enemigos.begin();
		EnemyIndex E_Enemy = enemigos.end();

		while (I_Enemy != E_Enemy)
		{
			Enemy* enem = (*I_Enemy);

			// Recorre todas la balas - Cargadas
			ChargedBeamIndex I = chargedBeams.begin();
			ChargedBeamIndex E = chargedBeams.end();

			while (I != E)
			{
				ProyectilChargedBeam* beam = (*I);
				if (!beam->isAlive())
				{
					++I;
					continue;
				}

				if (Collision::PixelPerfectTest(enem->spr, beam->getSprite()))
				{
					beam->kill();
					enem->bajarHp(beamCharged_daño);
					enem->moverPorImpacto(Retardos::Potente);
					break;
				}

				++I;
			};

			// Recorremos todas la balas normales
			BeamIndex I_beam = beams.begin();
			BeamIndex E_beam = beams.end();
			while (I_beam != E_beam)
			{
				Proyectil_beam* beam = (*I_beam);
				if (!beam->isAlive())
				{
					++I_beam;
					continue;
				}

				if (Collision::PixelPerfectTest(enem->spr, beam->getSprite()))
				{
					beam->kill();
					enem->bajarHp(bullet_daño);
					enem->moverPorImpacto(Retardos::Normal);
				}

				++I_beam;
			}

			if (enem->isAlive())
			{
				if (Collision::PixelPerfectTest(enem->spr, nave->getSprite()))
				{
					if (time_to_restar_vida <= 0.f)
					{
						nave->Golpearon();
						VIDAS--;
						time_to_restar_vida = 5.f;
					}
						
				}
			}


			++I_Enemy;

		}


		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exite
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// get dt
		float dt;
		{
			const auto new_tp = std::chrono::steady_clock::now();
			dt = std::chrono::duration<float>(new_tp - tp).count();
			tp = new_tp;
		}

		//A - Rutina de disparo cuando se pulsa espacion & se puede disparar
		time_to_next_bullet -= dt;
		time_to_next_bullet_charged -= dt;
		time_to_cambiar_disparo -= dt;

		// Espera un tiempo entre las pulsaciones para evitar posibles repeticiones
		if (Keyboard::isKeyPressed(sf::Keyboard::A) && time_to_cambiar_disparo < 0.0f)
		{
			if (actualDisparo == Disparos::Beam)
			{
				actualDisparo = Disparos::Charged_Beam;
				disparoLabel.cambiarDisparo();
				time_to_cambiar_disparo = 0.2f;
			}
			else
			{
				actualDisparo = Disparos::Beam;
				disparoLabel.cambiarDisparo();
				time_to_cambiar_disparo = 0.2f;
			}

		}

		if (Keyboard::isKeyPressed(sf::Keyboard::Space))
		{

			// Agregando balas a la lista

			// Calculamos la posicion de la bala
			sf::Vector2f posicion = nave->getPos();

			// movemos la posicion de la bala hasta la punta de la nave;
			posicion = { posicion.x + 3 , posicion.y - 20 };


			if (actualDisparo == Disparos::Beam && time_to_next_bullet < 0.0f)
			{
				time_to_next_bullet = bullet_shoot_speed_seconds; // reseteamos la frecuencia del disparo
				// Creamos la bala y la almacenamos
				Proyectil_beam* newBeam = new Proyectil_beam(posicion);
				if (newBeam) beams.push_back(newBeam);

			}

			if (actualDisparo == Disparos::Charged_Beam && time_to_next_bullet_charged < 0.0f)
			{
				time_to_next_bullet_charged = beamCharged_shoot_speed_seconds;

				// Creamos la bala y la almacenamos (Charged)
				ProyectilChargedBeam* newChargedBeam = new ProyectilChargedBeam(posicion);
				if (newChargedBeam) chargedBeams.push_back(newChargedBeam);
			}

		}

		// handle input
		sf::Vector2f dir = { 0.f,0.f };
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			dir.y -= 1.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			dir.y += 1.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			dir.x += 1.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			dir.x -= 1.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
		{
			nave->Miniatura();
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
		{
			nave->Normal();
		}


		nave->SetDireccion(dir);

		// update nave
		nave->Update(dt);


		// A - Actualizmos las balas de los normales
		BeamIndex I = beams.begin();
		BeamIndex E = beams.end();
		while (I != E)
		{
			Proyectil_beam* beam = (*I);

			if (beam->isAlive()) // Si la bala sigue viva se actualiza y pasamos a la siguiente
			{
				beam->Update(dt);
				++I;
			}
			else // Si la bala ha muerto se elimina y se pasa a la siguiente
			{
				delete beam;
				I = beams.erase(I);
			}
		};


		// B - Actualizmos las balas de las cargadas
		ChargedBeamIndex I_Charged = chargedBeams.begin();
		ChargedBeamIndex E_Charged = chargedBeams.end();
		while (I_Charged != E_Charged)
		{
			ProyectilChargedBeam* beam = (*I_Charged);

			if (beam->isAlive()) // Si la bala sigue viva se actualiza y pasamos a la siguiente
			{
				beam->Update(dt);

				++I_Charged;
			}
			else // Si la bala ha muerto se elimina y se pasa a la siguiente
			{
				delete beam;
				I_Charged = chargedBeams.erase(I_Charged);
			}
		};

		// C
		I_Enemy = enemigos.begin();
		E_Enemy = enemigos.end();
		while (I_Enemy != E_Enemy)
		{
			Enemy* enemigo = (*I_Enemy);

			if (enemigo->isAlive())
			{
				enemigo->Update(dt, nave->getPos());
				//Genera las balas

				// validaciones para que no se escape de la pantalla en x
				if (enemigo->getPosition().x >= 4.f && enemigo->getPosition().x <= 757.f) {
					if (enemigo->getPosition().y >= 0.5f && enemigo->getPosition().x <= 851.5f) {

						enemigo->time_to_next_enemybullet -= dt;
						if (enemigo->time_to_next_enemybullet <= 0) {

							//generarBalasEnemigas(*enemigo, balasEnemigas);
							enemigo->time_to_next_enemybullet = enemigo->frequencyBullet;
						}
					}
				}

				if (!enemigo->isAlive())
				{
					delete enemigo;
					I_Enemy = enemigos.erase(I_Enemy);
				}
				else
				{
					++I_Enemy;
				}
			}
			else
			{
				delete enemigo;
				I_Enemy = enemigos.erase(I_Enemy);
			}
		}

		// Clear screen
		window.clear();

		// Draw the sprite
		BG->Draw(window);
		nave->Draw(window);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			nave->ShowHitbox(window);

		}


		// A - Recorremos la lista de balas y las dibujamos
		I = beams.begin();
		E = beams.end();


		while (I != E)
		{
			Proyectil_beam* beam = (*I);

			beam->Draw(window);
			++I;
		}


		// B - recorre la lista de balas Charged
		I_Charged = chargedBeams.begin();
		E_Charged = chargedBeams.end();

		while (I_Charged != E_Charged)
		{
			ProyectilChargedBeam* beam = (*I_Charged);
			beam->Draw(window);

			++I_Charged;
		}

		// C - recorre la lista de enemigos
		I_Enemy = enemigos.begin();
		E_Enemy = enemigos.end();

		while (I_Enemy != E_Enemy)
		{
			Enemy* enemigo = (*I_Enemy);
			enemigo->Draw(window);

			++I_Enemy;
		}

		// D - recorre la lista de balas enemigas
		EnemyBulletIndex I_Bullet = balasEnemigas.begin();
		EnemyBulletIndex E_Bullet = balasEnemigas.end();
		while (I_Bullet != E_Bullet)
		{
			Enemy_Bullet* bullet = (*I_Bullet);

			bullet->Update(dt);

			if (!bullet->isAlive())
			{
				delete bullet;
				I_Bullet = balasEnemigas.erase(I_Bullet);
			}
			else
			{
				bullet->Draw(window);
				++I_Bullet;
			}
		}



		disparoLabel.draw(window);
		rondaLabel.draw(window);

		time_to_restar_vida -= dt;
		vidasLabel.actualizarVidas(VIDAS);
		vidasLabel.draw(window);


		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;

}