#include "tmxlite/Config.hpp"
#include "tmxlite/Map.hpp"
#include "SFML/Graphics.hpp"
#include "player.h"
#include "Level.h"
#include "EnemyManager.h"
#include "worker.h"

#include <iostream>
#include <vector>

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1600, 900), "Space Station Rescue");
	window->setFramerateLimit(60);
	sf::View camera;
	camera.setSize(800, 450);
	window->setView(camera);

	
	Player* player = new Player();
	Worker worker;


	Level level("level.tmx");

	EnemyManager enemyManager(level.getMap());

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				window->close();
			}
		}

		//update

		player->update(*window);
		worker.update();
		camera.setCenter(player->getPosition());
		level.update(player);
		window->setView(camera);
		
		//end update

		window->clear();
		
		level.draw(*window);
		enemyManager.drawEntities(*window);
		worker.draw(*window);
		player->draw(*window);
		window->display();
	}

	return 0;
}