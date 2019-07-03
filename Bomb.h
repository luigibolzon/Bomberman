#pragma once
#include"Char.h"

class Bomb:public Body
{
private:
	sf::Time OriginTime;
	Char *Owner;
public:
	Bomb(std::string, sf::Vector2i, sf::Vector2i, sf::Vector2f, Char *, sf::Time);
	~Bomb();
	Char *GetOwner();
	sf::Time GetOriginTime();
	int GetRange();
};