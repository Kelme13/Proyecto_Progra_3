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
	Star->setPosition(0.f, -6000.f);
}

void Background::Draw(sf::RenderTarget& rt) const {
	
	sprite->setOrigin(2900.f, 440.f);
	sprite->rotate(0.01f);
	sprite->setScale(3, 3);
	rt.draw(*sprite);
	Estrellas(rt);
}

void Background::Estrellas(sf::RenderTarget& rt) const {


	Star->setScale(1,1);
	if (Star->getPosition().y > 2500.f) {
		Star->setPosition(0.f, -6000.f);
	}
	Star->setColor(sf::Color(255, 255, 255, 128));

	Star->move(0.f, 0.4f);
	//Star->rotate(0.003f);



	rt.draw(*Star);



}