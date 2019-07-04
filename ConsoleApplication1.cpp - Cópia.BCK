#include "pch.h"
#include <iostream>
#include<thread>
#include <list>
#include <SFML/Graphics.hpp>

enum Direcao
{
	ESQUERDA, BAIXO, DIREITA, CIMA
};

bool colisao(std::list<sf::Sprite*> *Images, sf::Sprite *Image, Direcao dir) {
	switch (dir)
	{
	case ESQUERDA:
		break;
	case BAIXO:
		break;
	case DIREITA:
		break;
	case CIMA:
		break;
	default:
		break;
	}
	return false;
}

void MovePlayers(sf::Time *time, sf::Sprite* Image1, sf::Sprite* Image2, std::list<sf::Sprite*> *Images, int pspd, sf::RenderWindow *window) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !colisao(Images, Images->front(), ESQUERDA))
		if (Images->front()->getPosition().x > -20) Images->front()->move(-1 * pspd * time->asSeconds(), 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !colisao(Images, Images->front(), DIREITA))
		if (Images->front()->getPosition().x + Images->front()->getGlobalBounds().width < window->getSize().x + 20) Images->front()->move(1 * pspd*time->asSeconds(), 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !colisao(Images, Images->front(),  BAIXO))
		if (Images->front()->getPosition().y + Images->front()->getGlobalBounds().height < window->getSize().y) Images->front()->move(0, 1 * pspd*time->asSeconds());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !colisao(Images, Images->front(),  CIMA))
		if (Images->front()->getPosition().y > 0)Images->front()->move(0, -1 * pspd*time->asSeconds());


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		if (Images->back()->getPosition().x > -20) Images->back()->move(-1 * pspd * time->asSeconds(), 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		if (Images->back()->getPosition().x + Images->back()->getGlobalBounds().width < window->getSize().x + 20) Images->back()->move(1 * pspd*time->asSeconds(), 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (Images->back()->getPosition().y + Images->back()->getGlobalBounds().height < window->getSize().y) Images->back()->move(0, 1 * pspd*time->asSeconds());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (Images->back()->getPosition().y > 0)Images->back()->move(0, -1 * pspd*time->asSeconds());
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");

	int framecount = 0;
	sf::Event Event;
	sf::Time Time;
	sf::Clock Clock;
	sf::Texture pTexture;
	sf::Vector2i move(0,0);
	
	Clock.restart();
	if (Clock.restart().asMicroseconds() == 1000000000) return 0;
	if (Clock.restart().asMicroseconds() == 1000000000) return 0;
	if (Clock.restart().asMicroseconds() == 1000000000) return 0;
	if (Clock.restart().asMicroseconds() == 1000000000) return 0;
	if (Clock.restart().asMicroseconds() == 1000000000) return 0;
	std::cout << Clock.restart().asMicroseconds() << std::endl;

	sf::Sprite *p1Image, *p2Image;
	std::list<sf::Sprite*> *pImages;
	pImages = new std::list<sf::Sprite*>;

	p1Image = new sf::Sprite(pTexture);
	p2Image = new sf::Sprite(pTexture);
	p2Image->setPosition(window.getSize().x - p2Image->getGlobalBounds().width, window.getSize().y - p2Image->getGlobalBounds().height);

	if (!pTexture.loadFromFile("texture/bman.png"))
		std::cout << "error loading texture" << std::endl;

	pImages->push_back(p1Image);
	pImages->push_back(p2Image);


	Time = Clock.restart();
	while (window.isOpen()) {
		while (window.pollEvent(Event)) {
			switch (Event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (Event.key.code) {
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
				break;
			default:
				break;
			}
		}
		

		int pspd = 150;



		sf::Time timer = Clock.restart();
		MovePlayers(&timer, p1Image, p2Image, pImages, 150, &window);


		window.clear();
		window.draw(*pImages->front());
		window.draw(*pImages->back());
		window.display();
	}
}