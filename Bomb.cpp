#include "pch.h"
#include "Bomb.h"


Bomb::Bomb(sf::Texture* texture, sf::Vector2i spriteset, sf::Vector2i target, sf::Vector2f position, Char *owner, sf::Time origintime):Body("Bomb", texture, spriteset, target, position)
{
	this->Owner = owner;
	this->OriginTime = origintime;
}

Bomb::~Bomb()
{
}

Char * Bomb::GetOwner()
{
	return this->Owner;
}

sf::Time Bomb::GetOriginTime()
{
	return this->OriginTime;
}

int Bomb::GetRange()
{
	return Owner->GetRange();
}
