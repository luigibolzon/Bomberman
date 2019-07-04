#include "pch.h"
#include "Block.h"


//destructible
//file
//SpriteGrid
//target
//position
Block::Block(bool destructible, sf::Texture* texture, sf::Vector2i SpriteGrid, sf::Vector2i target, sf::Vector2f position):Body("Block", texture, SpriteGrid, target, position)
{
	this->Destructible = destructible;
}


Block::~Block()
{
}

