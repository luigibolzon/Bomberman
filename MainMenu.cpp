#include "pch.h"
#include "MainMenu.h"


MainMenu::MainMenu()
{
	Window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML Game");
	Events = new sf::Event();
	View = new sf::View();
}

void MainMenu::Show()
{
	Menu.loadFromFile("texture/MainScreen.png");
	sf::Sprite Sprite;
	Window->clear();
	Window->display();
	Sprite.setTexture(Menu);
	*View = Window->getDefaultView();
	View->zoom(1.5);
	View->setCenter(Sprite.getTextureRect().width/2, Sprite.getTextureRect().height/ 2);
	Window->setView(*View);
	while (true) {
		MenuEvents();
		Window->display();
		Window->draw(Sprite);
	}
}

void MainMenu::MenuEvents()
{
	while (Window->pollEvent(*Events)) {
		switch (Events->type)
		{
		case sf::Event::Closed:
			Window->close();
			break;
		case sf::Event::KeyPressed:
			switch (Events->key.code) {
			case sf::Keyboard::Escape:
				Window->close();
				break;
			case sf::Keyboard::Return:
			case sf::Keyboard::Space:
				StartGame();
				break;
			}
			break;
		default:
			break;
		}
	}
}

void MainMenu::StartGame()
{
	Scene = new Scenario({ "texture/blocks.png","texture/bomb.png","texture/player.png", "texture/gota.png", "texture/explosion.png",   "texture/bexiga.png" });
	while (true) {
		while (Window->pollEvent(*Events)) {
			switch (Events->type)
			{
			default:
				break;
			}
		}
		Window->display();
		Scene->UpdateScreen(Window);
	}
}



MainMenu::~MainMenu()
{
}
