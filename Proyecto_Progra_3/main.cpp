#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>


using namespace std;
using namespace sf;

int main() {

	int fps = 60;
	bool gameover= false;



	RenderWindow* Ventana1;
	Ventana1 = new RenderWindow(VideoMode(800, 600), "Hola");
	Ventana1->setFramerateLimit(fps);

	while (!gameover) {
		Ventana1->clear(Color::Magenta);

		Ventana1->display();
	}


	cout << "Aqui se empieza...";
	cout << "Un Push";
	return 0;
}