#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>

#include <list>

#include "Nave.h"
#include "Background.h"
#include "Proyectil_beam.h"
#include "Game.h"


using namespace std;
using namespace sf;


//A - Definiciones para mejor comprension del codigo
typedef list<Proyectil_beam*> BulletList;
typedef list<Proyectil_beam*>::iterator BulletIndex;

int main() {

    //Game* juego = new Game();


    sf::RenderWindow window(sf::VideoMode(800, 900), "SFML window");
    // Load a sprite to display

    Vector2f pos_centro = { window.getSize().x / 2.f, window.getSize().y - 100.f };

    Nave* nave = new Nave(pos_centro);


    Background* BG = new Background("Assets\\Backgrounds\\Dynamic\\Nebula Blue.png", "Assets\\Backgrounds\\Dynamic\\EstrellaTipo4.png");

    // timepoint for delta time measurment
    std::chrono::steady_clock::time_point tp = std::chrono::steady_clock::now();

    //A - Contenedor de todas las balas disparadas
    BulletList bullets;
    float time_to_next_bullet = 0.0f;	//A - Control de la fracuencia de disparo


    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
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
        if (Keyboard::isKeyPressed(sf::Keyboard::Space) && time_to_next_bullet < 0.0f)
        {
            time_to_next_bullet = bullet_shoot_speed_seconds; // reseteamos la frecuencia del disparo

            // Calculamos la posicion de la bala
            sf::Vector2f posicion = nave->getPos();

            // movemos la posicion de la bala hasta la punta de la nave;
            posicion = { posicion.x + 3 , posicion.y - 20 };

            // Creamos la bala y la almacenamos
            Proyectil_beam* newBeam = new Proyectil_beam(posicion);
            if (newBeam) bullets.push_back(newBeam);

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


        // A - Actualizmos las balas
        BulletIndex I = bullets.begin();
        BulletIndex E = bullets.end();
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
                I = bullets.erase(I);
            }
        };


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
        I = bullets.begin();
        E = bullets.end();

        while (I != E)
        {
            Proyectil_beam* beam = (*I);

            beam->Draw(window);
            ++I;
        }

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;

}