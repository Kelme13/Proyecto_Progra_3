#include "MainMenu.h"

MainMenu::MainMenu()
{
	if (!font.loadFromFile("Font\\SPACEBOY.TTF")) {
		cout << "e";
}
	Abierto = true;
	//Jugar
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Jugar");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(100.f, 200.f);

	//Opciones
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Opciones");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(100.f, 300.f);

	//Records
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Records");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(100.f, 400.f);

	//Jugar
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Salir");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(100.f, 500.f);

	MainMenuSelected = -1;
}

void MainMenu::Draw(RenderWindow& rt)
{
	for (int i = 0; i < OpcionesMenu; i++) {
		rt.draw(mainMenu[i]);
	}

}

void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= -1) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected--;

		if (MainMenuSelected == -1) {
			MainMenuSelected = 3;
		}

		mainMenu[MainMenuSelected].setFillColor(Color::Yellow);
	}


}

void MainMenu::MoveDown()
{

	if (MainMenuSelected + 1 <= OpcionesMenu) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected++;

		if (MainMenuSelected == 4) {
			MainMenuSelected = 0;
		}

		mainMenu[MainMenuSelected].setFillColor(Color::Yellow);
	}
}
