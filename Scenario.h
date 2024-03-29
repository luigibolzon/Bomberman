#pragma once
#include "Block.h"
#include "Bomb.h"
#include "Char.h"
#include "Explosion.h"
#include <list>
#include <deque>

class Scenario
{
private:

	std::vector<std::string> Texture;
	std::vector<sf::Texture*> Textures;

	sf::Vector2i Size;
	sf::Vector2i BlockCount;
	sf::RectangleShape Base;
	std::vector<Char*> *Player;
	std::vector<Block*> *BlockList;
	std::vector<Block*> *DestructableBlockList;
	std::vector<Bomb*> *Bombs;
	int blockdistance = 18;
public:
	sf::RectangleShape GetBase();
	Scenario(std::vector<std::string>);
	void DrawChar(sf::RenderWindow*);
	void DrawBlocks(sf::RenderWindow*);
	void DrawDestructableBlocks(sf::RenderWindow*);
	void GenBlocks();
	void GenPlayer();
	void UpdateScreen(sf::RenderWindow*);
	void CheckColisions();
	~Scenario();
	//Block, Bomb, Char(player), Char(Mob), Explosion;
	void SetTextures(std::string, std::string, std::string, std::string, std::string);
};