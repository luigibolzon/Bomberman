#pragma once
#include "Scenario.h"
#include <SFML/Graphics.hpp>
#include <iostream>
class MainMenu
{
private:
	sf::Texture Menu;
	sf::RenderWindow *Window;
	sf::Event *Events;
	sf::View *View;
	Scenario *Scene;
public:
	MainMenu();
	~MainMenu();
	void Show();
	void MenuEvents();
	void StartGame();
	void Pause();
	bool Close();
};