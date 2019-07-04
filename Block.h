#pragma once
#include "Body.h"
class Block : public Body
{
private:
	bool Destructible;
public:
	//destructible
	//file
	//SpriteGrid
	//target
	//position
	Block(bool, sf::Texture*, sf::Vector2i, sf::Vector2i, sf::Vector2f);
	~Block();
};