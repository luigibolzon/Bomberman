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

	BlockList = new std::vector<Block*>;
	DestructableBlockList = new std::vector<Block*>;

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
		Char->Walk();
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
	//for (Block *block : *DestructableBlockList)
	//{
	//	if (block->IsExploding())
	//		if (block->DeathAnimation()) {
	//			//delete block;
	//			DestructableBlockList->erase());
	//			continue;
	//			//BlockList->(block);
	//		}
	//	screen->draw(block->GetSprite());
	//}

	std::vector<Block*> &DestructableBlockLists = *DestructableBlockList;
	for (int i = 0; i < DestructableBlockList->size(); i++) {
			if (DestructableBlockLists[i]->IsExploding())
				if (DestructableBlockLists[i]->DeathAnimation()) {
					//DestructableBlockList.erase(DestructableBlockLists[i]);
					//DestructableBlockList->erase();
					continue;
					//BlockList->(block);
				}
			screen->draw(DestructableBlockLists[i]->GetSprite());
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
	for (int i = 0; i < 10; i++) {
		sf::Vector2f position;
		bool test = false;
		do{
			test = false;
			position.x = rand() % BlockCount.x * blockdistance + this->Base.getPosition().x + 1;
			position.y = rand() % BlockCount.y * blockdistance + this->Base.getPosition().y + 1;
			for (Block* block : *BlockList) {
				if (block->GetPosition().x == position.x && block->GetPosition().y == position.y)
					test = true;
			}
		}while(test);
		DestructableBlockList->push_back(new Block(true, Textures[0],sf::Vector2i(6, 2), sf::Vector2i(1, 0), position));
	}
}

void Scenario::GenPlayer()
{
	Player = new std::vector<Char*>();
	Player->push_back(new Char(" Player" , Textures[2], sf::Vector2i(7,5), sf::Vector2i(2,2), sf::Vector2f(0,0)));
	Player->back()->SetMovKeys({sf::Keyboard::Key::W,sf::Keyboard::Key::S, sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::Space});
}

void Scenario::UpdateScreen(sf::RenderWindow* screen)
{
	sf::View view = screen->getDefaultView();
	view.zoom(0.69f);
	view.setCenter(this->GetBase().getSize().x / 2, this->GetBase().getSize().y / 2);
	screen->setView(view);
	CheckColisions();
	DrawBlocks(screen);
	DrawChar(screen);
	DrawDestructableBlocks(screen);
}

void Scenario::CheckColisions()
{
	Body::ColisionDir tmp;
	for (Char* Char : *Player) {
		tmp.BOTTOM = false;
		tmp.TOP = false;
		tmp.LEFT = false;
		tmp.RIGHT = false;
		Char->Colision = tmp;
		for (Block* Block : *BlockList)
		{
			Char->IsColiding(Block);
			if (Char->Colision.BOTTOM)
				tmp.BOTTOM = true;
			if (Char->Colision.TOP)
				tmp.TOP = true;
			if (Char->Colision.LEFT)
				tmp.LEFT = true;
			if (Char->Colision.RIGHT)
				tmp.RIGHT = true;
		}
		for (Block* Block : *DestructableBlockList)
		{
			if (Char->IsColiding(Block))
				Block->Explode();
			if (Char->Colision.BOTTOM)
				tmp.BOTTOM = true;
			if (Char->Colision.TOP)
				tmp.TOP = true;
			if (Char->Colision.LEFT)
				tmp.LEFT = true;
			if (Char->Colision.RIGHT)
				tmp.RIGHT = true;
		}
		Char->Colision = tmp;
	}
}

Scenario::~Scenario()
{
}