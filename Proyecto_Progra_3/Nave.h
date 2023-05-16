#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Nave
{
private:
	Vector2f pos;
	Vector2f vel;
	CircleShape hitbox;

	static  constexpr float speed = 200.0f;

	Texture* textura;
	Sprite* spr;

	IntRect frames[3];

	IntRect movimientos[3];
	int iFrame;
	enum class AnimationIndex
	{
		LeftMov,
		Non,
		RighMov,
		Count
	};

	AnimationIndex curAnimation = AnimationIndex::RighMov;


public:
	Nave(Vector2f& pos_a);
	~Nave();
	void ShowHitbox(RenderTarget& rt) const;
	void Draw(RenderTarget& rt) const;  
	void SetDireccion(const Vector2f& dir);
	void Update(float dt);
	Vector2f getPos();


};


