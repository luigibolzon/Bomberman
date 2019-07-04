#include "pch.h"
#include "Explosion.h"


//file
//spriteset
//target
//position
//range
Explosion::Explosion(sf::Texture* texture, sf::Vector2i spriteset, sf::Vector2i target, sf::Vector2f position, int range):Body("Explosion", texture, spriteset, target, position)
{
	this->Range = range;
}


Explosion::Explosion(sf::Texture* texture, sf::Vector2i spriteset, sf::Vector2i target, Bomb * origin):Body("Explosion", texture, spriteset, target, origin->GetPosition())
{
	Explosion(texture, spriteset, target, origin->GetPosition(), origin->GetRange());
}

Explosion::~Explosion()
{
}
