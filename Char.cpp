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

void Char::SetMovKeys(std::vector<sf::Keyboard::Key> keys)
{
	this->MovementKeys.up = keys[0];
	this->MovementKeys.down = keys[1];
	this->MovementKeys.left = keys[2];
	this->MovementKeys.right = keys[3];
	this->MovementKeys.plant = keys[4];
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

void Char::Walk()
{
	if (this->Colision.TOP || this->Colision.BOTTOM || this->Colision.LEFT || this->Colision.RIGHT)
		std::cout << this->Colision.TOP << " " << this->Colision.BOTTOM << " " << this->Colision.LEFT << " " << this->Colision.RIGHT << "    " << rand() << std::endl;

	sf::Time Time = MovementClock.restart();
	if (sf::Keyboard::isKeyPressed(this->MovementKeys.up) && !this->Colision.TOP)
		this->Move(sf::Vector2f(0,-MovementSpeed*Time.asSeconds()));
	if (sf::Keyboard::isKeyPressed(this->MovementKeys.down) && !this->Colision.BOTTOM)
		this->Move(sf::Vector2f(0, MovementSpeed * Time.asSeconds()));
	if (sf::Keyboard::isKeyPressed(this->MovementKeys.left) && !this->Colision.LEFT)
		this->Move(sf::Vector2f(-MovementSpeed * Time.asSeconds(),0));
	if (sf::Keyboard::isKeyPressed(this->MovementKeys.right) && !this->Colision.RIGHT)
		this->Move(sf::Vector2f(MovementSpeed * Time.asSeconds(),0));
}
