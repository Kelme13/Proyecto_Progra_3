#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "Game.h"

using namespace std;
using namespace sf;

int main() {
		Game* juego = new Game(800, 900, "Wenas");
	return 0;
}