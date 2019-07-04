#pragma once
#include"Bomb.h"
class Explosion:Body
{
private:
	int Range;
	Bomb *Origin;
public:
	Explosion(sf::Texture*, sf::Vector2i, sf::Vector2i, sf::Vector2f, int);
	Explosion(sf::Texture*, sf::Vector2i, sf::Vector2i, Bomb *);
	~Explosion();
};

