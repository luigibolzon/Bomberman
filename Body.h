#pragma once
#include<iostream>
#include<list>
#include <SFML/Graphics.hpp>



class Body
{
private:
	sf::Clock AnimationClock;
	double AnimationSpeed = 0.16;
	bool AnimationFlow = true, Exploding = false;
	std::string Name;
	sf::Sprite Sprite;
	sf::Texture Texture;
	sf::Vector2i SpriteGrid;
	sf::Vector2i CurrentSprite;
	sf::IntRect SpriteRect; //Identifies the rectangle that limits the Sprite in the texture (temporary)
	void ChangeSprite(sf::Vector2i);
public:
	struct Coliding {
		bool LEFT =false, RIGHT = false, UP = false, DOWN = false;
	}Colision;

	Body(std::string, std::string, sf::Vector2i, sf::Vector2i, sf::Vector2f);
	Body(std::string, sf::Vector2i, sf::Vector2i, sf::Vector2f);
	~Body();
	void SetPosition(sf::Vector2f);
	sf::Vector2f GetPosition();
	void SetName(std::string);
	std::string GetName();
	sf::Sprite GetSprite();
	sf::Vector2i GetSize();
	sf::IntRect GetRectangle();
	virtual void Animation();
	bool DeathAnimation();
	void Move(sf::Vector2f);
	void SetAnimationSpeed(double);
	double GetAnimationSpeed();
	bool IsColiding(Body *);
};