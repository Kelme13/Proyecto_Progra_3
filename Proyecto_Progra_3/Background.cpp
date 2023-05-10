#include "Background.h"
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

Background::Background(const char* BackgroundFile, const char* EstrellaFile){

	Textura = new Texture();
	Textura->loadFromFile(BackgroundFile);

	ancho = Textura->getSize().x;
	alto = Textura->getSize().y;

	sprite = new Sprite(*Textura);
	sprite->setTexture(*Textura);
	sprite->setTextureRect(sf::IntRect(0, 0, ancho, alto));

	Estrella = new Texture();
	Estrella->loadFromFile(EstrellaFile);

	Star = new Sprite(*Estrella);
	Star->setTexture(*Estrella);

}

void Background::Draw(sf::RenderTarget& rt) const {
	
	sprite->setOrigin(2900.f, 440.f);
	sprite->rotate(0.01f);
	sprite->setScale(3, 3);
	Estrellas(rt);
	rt.draw(*sprite);
}

void Background::Estrellas(sf::RenderTarget& rt) const {


	Star->setScale(2,2);
	/*if (Star->getPosition().y > 1000) {
		Star->setPosition(0, 0);
	}*/
	

	//Star->move(0.f, 0.2f);
	



	rt.draw(*Star);



}