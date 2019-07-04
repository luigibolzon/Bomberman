#include "pch.h"
#include "Char.h"


Char::Char(std::string name, sf::Texture* texture, sf::Vector2i spriteset, sf::Vector2i target, sf::Vector2f position):Body(name, texture, spriteset, target, position)
{
	Range = 4;
	Speed = 1;
	BombQt = 4;
	Kill = Death = Suicide = Score = 0;
	Intangible = Invulnerable = false;
}

Char::Char(sf::Texture* texture, sf::Vector2i spriteset, sf::Vector2i target, sf::Vector2f position):Body(texture, spriteset, target, position)
{
	Char("generic", texture, spriteset, target, position);
}

Char::~Char()
{
}

void Char::SetRange(int range)
{
	this->Range = range;
}

int Char::GetRange()
{
	return this->Range;
}

void Char::SetBombQt(int bomb)
{
	this->BombQt = bomb;
}

int Char::GetBomb()
{
	return this->BombQt;
}

void Char::SetSpeed(double speed)
{
	this->Speed = speed;
}

double Char::GetSpeed()
{
	return this->Speed;
}

void Char::SetIntangible(bool intan)
{
	this->Intangible = intan;
}

bool Char::GetIntangible()
{
	return this->Intangible;
}

void Char::SetInvulnerable(bool invulnerable)
{
	this->Invulnerable = invulnerable;
}

bool Char::GetInvulnerable()
{
	return this->Invulnerable;
}

void Char::SetKill(int kill)
{
	this->Kill = kill;
}

int Char::GetKill()
{
	return this->Kill;
}

void Char::SetDeath(int death)
{
	this->Death = death;
}

int Char::GetDeath()
{
	return this->Death;
}

void Char::SetSuicide(int suicide)
{
	this->Suicide = suicide;
}

int Char::GetSuicide()
{
	return this->Suicide;
}

void Char::SetScore(int score)
{
	this->Score = score;
}

int Char::GetScore()
{
	return this->Score;
}
