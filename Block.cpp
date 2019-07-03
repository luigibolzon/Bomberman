#include "pch.h"
#include "Block.h"


Block::Block(bool destructible,std::string file, sf::Vector2i SpriteGrid, sf::Vector2i target, sf::Vector2f position):Body("Block", file, SpriteGrid, target, position)
{
	this->Destructible = destructible;
}


Block::~Block()
{
}

