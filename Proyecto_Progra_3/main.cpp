#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include "Nave.h"
#include "Background.h"

using namespace std;
using namespace sf;

int main() {


    sf::RenderWindow window(sf::VideoMode(800, 900), "SFML window");
    // Load a sprite to display

    Vector2f pos_centro = { window.getSize().x / 2.f, window.getSize().y - 100.f };

    Nave* nave = new Nave(pos_centro);


    Background* BG = new Background("Assets\\Backgrounds\\Dynamic\\Nebula Blue.png", "Assets\\Backgrounds\\Dynamic\\EstrellaTipo4.png");

    // timepoint for delta time measurment
    std::chrono::steady_clock::time_point tp = std::chrono::steady_clock::now();

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

        // update lulu
        nave->Update(dt);

        // Clear screen
        window.clear();
        // Draw the sprite
        BG->Draw(window);
        nave->Draw(window);
        
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;

}