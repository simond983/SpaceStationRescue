#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_h

#include "tmxlite/Config.hpp"
#include "tmxlite/Map.hpp"
#include "tmxlite/Object.hpp"
#include "tmxlite/ObjectGroup.hpp"

#include "SFML/Graphics.hpp"
#include "AlienNest.h"

#include <vector>

///Class for managing collections of different enemy entities in the game
class EnemyManager
{
public:
	EnemyManager();
	EnemyManager(tmx::Map* map);
	void updateEntities();
	void drawEntities(sf::RenderWindow &window);
private:
	std::vector<AlienNest*> m_alienNestVector;
	tmx::Map* m_mapRef;
	const int MAX_NESTS = 3;
	const int TILE_WIDTH = 32;
	const int TILE_HEIGHT = 32;
};


#endif 