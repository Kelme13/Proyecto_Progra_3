#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;


class Animation
{
public:
	Animation(int x, int y, int width, int height);
	Animation() = default;

	void ApplyToSprite(Sprite& s) const;

	void Update(float dt);

private:
	void Advance();

private:
	static constexpr int nFrames = 3;
	static constexpr float holdTime = 0.1f;
	Texture textura;

	// Los frames los guardamos en un arreglo de rectangulos para que su manipulacion sea mas sencilla
	IntRect frames[nFrames];
	// Representa el frame que esta actualmente
	int iFrame = 2;

	float time = 0.f;


};

class Nave
{	
private:
	Vector2f pos;
	Vector2f vel;

	static  constexpr float speed = 200.0f;

	Texture* textura;
	Sprite* spr;


	enum class AnimationIndex
	{
		LeftMov,
		Non,
		RighMov,
		Count
	};

	Animation* animations[int(AnimationIndex::Count )]; 
	AnimationIndex curAnimation = AnimationIndex::RighMov;


public:
	Nave(Vector2f& pos_a);
	~Nave();

	void Draw(RenderTarget& rt) const;  
	void SetDireccion(const Vector2f& dir);
	void Update(float dt);


};


