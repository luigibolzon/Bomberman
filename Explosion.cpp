#include "pch.h"
#include "Explosion.h"


//file
//spriteset
//target
//position
//range
Explosion::Explosion(std::string file, sf::Vector2i spriteset, sf::Vector2i target, sf::Vector2f position, int range):Body("Explosion", file, spriteset, target, position)
{
	this->Range = range;
}


Explosion::Explosion(std::string file, sf::Vector2i spriteset, sf::Vector2i target, Bomb * origin):Body("Explosion", file, spriteset, target, origin->GetPosition())
{
	Explosion(file, spriteset, target, origin->GetPosition(), origin->GetRange());
}

Explosion::~Explosion()
{
}
