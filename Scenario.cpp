#include "pch.h"
#include "Scenario.h"
#include <iostream>

sf::RectangleShape Scenario::GetBase()
{
	return Base;
}

Scenario::Scenario(std::vector<std::string> textures)
{
	Texture = textures;
	for (int i = 0; i < Texture.size(); i++) {
		Textures.push_back(new sf::Texture());
		Textures[i]->loadFromFile(Texture[i]);
	}
	
	srand(time(NULL));

	this->BlockCount = sf::Vector2i(29, 21);

	BlockList = new std::list<Block*>;

	this->Base.setSize(sf::Vector2f(BlockCount.x * blockdistance, BlockCount.y * blockdistance));
	this->Base.setFillColor(sf::Color::Green);
	this->Base.setOutlineThickness(20);
	//this->Base.setPosition(this->Base.getOutlineThickness(), this->Base.getOutlineThickness());
	this->Base.setOutlineColor(sf::Color(119,119,119,100));

	GenBlocks();

	GenPlayer();
}

void Scenario::DrawChar(sf::RenderWindow * screen)
{
	for (Char* Char : *Player) {
		screen->draw(Char->GetSprite());
	}
}

void Scenario::DrawBlocks(sf::RenderWindow *screen)
{
	screen->clear();
	screen->draw(Base);
	for (Block *block : *BlockList)
	{
		screen->draw(block->GetSprite());
	}
}

void Scenario::DrawDestructableBlocks(sf::RenderWindow *screen)
{
	for (Block *block : *DestructableBlockList)
	{
		if (block->IsExploding())
			if (block->DeathAnimation())
				BlockList->remove(block);
		screen->draw(block->GetSprite());
	}
}

void Scenario::GenBlocks()
{
	for (int i = 0; i < BlockCount.x; i++) {
		if (i % 2 == 1)for (int j = 0; j < BlockCount.y; j++) {
			if (j % 2 == 1) {
				BlockList->push_back(new Block(false, Textures[0],
					sf::Vector2i(6, 2), sf::Vector2i(0, 0), sf::Vector2f(i * blockdistance + this->Base.getPosition().x + 1,
						j * blockdistance + this->Base.getPosition().y + 1)));
			}
		}
	}
}

void Scenario::GenPlayer()
{
	Player = new std::list<Char*>();
	Player->push_back(new Char(" Player" , Textures[2], sf::Vector2i(7,5), sf::Vector2i(2,2), sf::Vector2f(0,0)));
}

void Scenario::UpdateScreen(sf::RenderWindow* screen)
{
	sf::View view = screen->getDefaultView();
	view.zoom(0.69f);
	view.setCenter(this->GetBase().getSize().x / 2, this->GetBase().getSize().y / 2);
	screen->setView(view);
	DrawBlocks(screen);
	DrawChar(screen);
	//DrawDestructableBlocks(screen);
}

Scenario::~Scenario()
{
}