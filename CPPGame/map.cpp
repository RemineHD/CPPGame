#include "map.h"
#include "textureManager.h"

int level1[Game::levelSizeY][Game::levelSizeX] = {
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,2,1 },
	{ 0,2,0,0,2,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,2,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,2,0,1 },
	{ 0,0,0,0,0,0,0,0,2,0,0,0,0,0,1 },
	{ 0,0,0,0,0,2,0,0,0,0,2,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

Map::Map()
{
	dirt = TextureManager::loadTexture("assets/dirt.png");
	grass = TextureManager::loadTexture("assets/grass.png");
	water = TextureManager::loadTexture("assets/water.png");

	loadMap(level1);

	src.x = 0; 
	src.y = 0;
	src.w = 32;
    dest.w = src.w * 4;
	src.h = 32;
	dest.h = src.h * 4;

	dest.x = dest.y = 0;

}

void Map::loadMap(int arr[Game::levelSizeY][Game::levelSizeX])
{
	for (int row = 0; row < Game::levelSizeY; row++)
	{
		for (int column = 0; column < Game::levelSizeX; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void Map::drawMap()
{

	int type = 0;

	for (int row = 0; row < Game::levelSizeY; row++)
	{
		for (int column = 0; column < Game::levelSizeX; column++)
		{
			type = map[row][column];

			dest.x = column * dest.w;
			dest.y = row * dest.h;

			switch (type)
			{
				case 0:
					TextureManager::draw(water, src, dest);
					break;
				case 1:
					TextureManager::draw(grass, src, dest);
					break;
				case 2:
					TextureManager::draw(dirt, src, dest);
					break;
				default:
					break;
			}

		}
	}
}