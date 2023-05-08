#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Nave
{	
private:
	Vector2f pos;
	Vector2f vel;

	static  constexpr float speed = 100.0f;

	Texture* textura;
	Sprite* spr;


public:
	Nave(Vector2f pos_a);
	~Nave();

	void Draw(RenderTarget& rt) const;  
	void SetDireccion(const Vector2f& dir);
	void Update(float dt);

};

