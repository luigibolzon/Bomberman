#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	int framecount = 0;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");
	sf::Event Event;
	sf::Time Time;
	sf::Clock Clock;
	sf::Texture pTexture;
	sf::Sprite pImage;
	sf::Vector2i move(0,0);
	if (!pTexture.loadFromFile("sprite/bman.png"))
		std::cout << "error loading sprite" << std::endl;
	pImage.setTexture(pTexture);
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
		if (Clock.getElapsedTime().asMilliseconds() %17 == 0) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				if(pImage.getPosition().x >-20) pImage.move(-1, 0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				if (pImage.getPosition().y + pImage.getGlobalBounds().height < window.getSize().y) pImage.move(0, 1);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				if (pImage.getPosition().x + pImage.getGlobalBounds().width < window.getSize().x+20) pImage.move(1, 0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				if (pImage.getPosition().y > 0)pImage.move(0, -1);
		}


		window.clear();
		window.draw(pImage);
		window.display();
		//std::cout << Clock.getElapsedTime().asMicroseconds()<<std::endl;
	}
}
