#include "Background.h"

Background::Background(const char* BackgroundFile){

	Textura = new Texture();
	Textura->loadFromFile(BackgroundFile);

	ancho = Textura->getSize().x;
	alto = Textura->getSize().y;

	sprite = new Sprite(*Textura);
	sprite->setTexture(*Textura);
	sprite->setTextureRect(sf::IntRect(0, 0, ancho, alto));


}

void Background::Draw(sf::RenderTarget& rt) const {
	

	int frame = (sprite->getTextureRect().left + ancho) % Textura->getSize().x;
	
	sprite->setTextureRect(sf::IntRect(frame, 0, ancho, alto));

	rt.draw(*sprite);
}