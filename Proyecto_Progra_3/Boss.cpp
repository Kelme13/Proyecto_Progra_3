#include "Boss.h"

Boss::Boss(int hp, int barras, Vector2f pos)
{
	this->MaxHP = hp;
	HP = MaxHP;
	this->BarrasVida = barras;
	this->Pos = pos;
	
	texture.loadFromFile("Assets\\Mini Pixel Pack 3\\Enemies\\Bon_Bon (16 x 16).png");
	time_to_next_enemybullet = 0.0f;
	BossAlive = true;

	spr.setTexture(texture);
	spr.setPosition(pos);
	spr.setScale(10, 10);
	spr.setTextureRect({ 16, 0, 16, 16 });

}

bool Boss::Aparecer()
{

	if (Pos.y >= 700.0f) {
		spr.move(0.0f, 10.0f);
	}
	else {
		spr.move(0.0f, 0.0f);
	}

	return true;
}

bool Boss::isAlive()
{
	return BossAlive;
}

void Boss::bajarHp(int daño)
{
	HP -= daño;

	if (HP <= 0 && BarrasVida > 0) {
		BarrasVida--;
		HP = MaxHP;
	}

}

void Boss::Draw(RenderTarget& rt) const
{
	rt.draw(spr);
}

void Boss::Update(float dt)
{

	if (BarrasVida <= 0)
	{
		animaciones_explosion.Update(dt);
		animaciones_explosion.ApplyToSprite(spr);

		if (animaciones_explosion.esUltimoFrame())
		{
			BossAlive = false;
		}

	}
	else
	{
		animation.Update(dt);
		animation.ApplyToSprite(spr);
	}
}

void Boss::Shoot(list<Enemy_Bullet*>& EnemyBulletList)
{
	//Diferentes patrones
	int random = 1 + (rand() % 3);
	Vector2f pos1;
	Vector2f pos2;
	Vector2f pos3;

	Enemy_Bullet* bul1;
	Enemy_Bullet* bul2;
	Enemy_Bullet* bul3;

	switch (random) {

	case 1:
		pos1 = { this->getPosition().x + 2, this->getPosition().y };
		 pos2 = { this->getPosition().x + 6, this->getPosition().y };
		 pos3 = { this->getPosition().x + 9, this->getPosition().y };

		bul1 = new Enemy_Bullet(pos1);
		bul1->getSprite().rotate(-15);

	bul2 = new Enemy_Bullet(pos2);
	
	bul3 = new Enemy_Bullet(pos3);
		bul3->getSprite().rotate(15);

		EnemyBulletList.push_back(bul1);
		EnemyBulletList.push_back(bul2);
		EnemyBulletList.push_back(bul3);
		break;

	case 2:

		 pos1 = { this->getPosition().x, this->getPosition().y };
		 pos2 = { this->getPosition().x + 6, this->getPosition().y };
		pos3 = { this->getPosition().x + 10, this->getPosition().y };

		 bul1 = new Enemy_Bullet(pos1);
		bul1->getSprite().rotate(-20);

		 bul2 = new Enemy_Bullet(pos2);

		 bul3 = new Enemy_Bullet(pos3);
		bul3->getSprite().rotate(20);

		EnemyBulletList.push_back(bul1);
		EnemyBulletList.push_back(bul2);
		EnemyBulletList.push_back(bul3);
		break;


	case 3:
		 pos1 = { this->getPosition().x + 4, this->getPosition().y };
		 pos2 = { this->getPosition().x + 6, this->getPosition().y };
		 pos3 = { this->getPosition().x + 8, this->getPosition().y };

	    bul1 = new Enemy_Bullet(pos1);
		bul1->getSprite().rotate(-10);

	 bul2 = new Enemy_Bullet(pos2);

			 bul3 = new Enemy_Bullet(pos3);
		bul3->getSprite().rotate(10);

		EnemyBulletList.push_back(bul1);
		EnemyBulletList.push_back(bul2);
		EnemyBulletList.push_back(bul3);
		break;
		
	}
}
