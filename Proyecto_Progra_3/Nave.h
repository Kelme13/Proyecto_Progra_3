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
	Nave(RenderTarget& rt);
	~Nave();

	void Draw(RenderTarget& rt) const;  
	void SetDireccion(const Vector2f& dir);
	void Update(float dt);



};

