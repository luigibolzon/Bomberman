#pragma once
#include"Body.h"

class Char:public Body
{
private:
	sf::Clock MovementClock;
	double MovementSpeed = 20;
	int Range, BombQt, Kill, Death, Suicide, Score;
	double Speed;
	bool Intangible, Invulnerable;
public:
	struct MovKeys
	{
		sf::Keyboard::Key up, down, left, right, plant;
	}MovementKeys;
	Char(std::string, sf::Texture*, sf::Vector2i, sf::Vector2i, sf::Vector2f);
	Char(sf::Texture*, sf::Vector2i, sf::Vector2i, sf::Vector2f);
	~Char();
	void SetMovKeys(std::vector<sf::Keyboard::Key>);
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
	void Walk();
};