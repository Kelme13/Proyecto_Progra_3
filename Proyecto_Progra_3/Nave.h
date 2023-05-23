#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;


class Animation_Booster
{
public:

	Animation_Booster() = default;

	Animation_Booster(String tx)
	{
		texture.loadFromFile(tx);
		for (int i = 0; i < nFrames; i++)
		{
			frames[i] = { 16 * i, 0, 16, 16 };
		}
	}

	void ApplyToSprite(Sprite& s) const
	{
		s.setTexture(texture);
		s.setTextureRect(frames[iframe]);
		//s.setScale(130.f / (float)s.getTexture()->getSize().x, 50.f / (float)s.getTexture()->getSize().y);
	}


	void Update(float dt)
	{
		time += dt;

		while (time >= holdTime)
		{
			time -= holdTime;
			Advance();
		}
	}

private:
	void Advance()
	{
		if (++iframe >= nFrames)
		{
			iframe = 0;
		}
	}
	static constexpr int nFrames = 2;
	static constexpr float holdTime = 0.1f;
	sf::Texture texture;
	sf::IntRect frames[nFrames];
	int iframe = 0;
	float time = 0.0f;
};


class Nave
{
private:
	Vector2f pos;
	Vector2f vel;
	CircleShape hitbox;
	
	/*
	* componeste de la animacion boosters
	Arreglos que indican los siguiente:
	0 - booster center
	1 - booster right
	2 - booster left
	*/


	Animation_Booster animaciones[3];
	Sprite spr_booster;
	int iFrame_booster = 0;

	/*
	Componentes de la nave y generales
	*/
	static  constexpr float speed = 200.0f;

	Texture* textura;
	Sprite* spr;

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
	void Miniatura();
	void Normal();
	Vector2f getPos();


};



