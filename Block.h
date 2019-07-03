#pragma once
#include "Body.h"
class Block : public Body
{
private:
	bool Destructible;
public:
	Block(bool, std::string, sf::Vector2i, sf::Vector2i, sf::Vector2f);
	~Block();
};