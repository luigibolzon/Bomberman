#pragma once
#include"Body.h"

class Char:Body
{
public:
	Char(std::string, std::string, sf::Vector2i, sf::Vector2i, sf::Vector2f);
	Char(std::string, sf::Vector2i, sf::Vector2i, sf::Vector2f);
	~Char();
	void SetRange(int);
	int GetRange();
	void SetBombQt(int);
	int GetBomb();
	void SetSpeed(double);
	double GetSpeed();
	void SetIntangible(bool);
	bool GetIntangible();
	void SetInvulnerable(bool);
	bool GetInvulnerable();
	void SetKill(int);
	int GetKill();
	void SetDeath(int);
	int GetDeath();
	void SetSuicide(int);
	int GetSuicide();
	void SetScore(int);
	int GetScore();

private:
	int Range, BombQt, Kill, Death, Suicide, Score;
	double Speed;
	bool Intangible, Invulnerable;
};