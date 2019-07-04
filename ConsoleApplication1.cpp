#include "pch.h"
#include "MainMenu.h"
#include <iostream>


MainMenu Menu;
Scenario *Scene;

int main() {
	Menu.Show();
};


void old(){
sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");
	sf::Event Events;
	//Block, Bomb, Char(player), Char(Mob), Explosion;
	Scene = new Scenario({ "texture/blocks.png","texture/bomb.png","texture/player.png", "texture/gota.png", "texture/explosion.png",   "texture/bexiga.png" });
	window.clear();
	sf::View view = window.getDefaultView();
	view.zoom(0.69f);
	view.setCenter(Scene->GetBase().getSize().x / 2, Scene->GetBase().getSize().y / 2);
	window.setView(view);
		while (window.isOpen()) {
		window.pollEvent(Events);
		window.display();
		window.draw(Scene->GetBase());
		Scene->DrawBlocks(&window);
	}
}