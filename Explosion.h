#pragma once
#include"Bomb.h"
class Explosion:Body
{
private:
	int Range;
	Bomb *Origin;
public:
	Explosion(std::string, sf::Vector2i, sf::Vector2i, sf::Vector2f, int);
	Explosion(std::string, sf::Vector2i, sf::Vector2i, Bomb *);
	~Explosion();
};

