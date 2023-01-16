#pragma once
#include "game.h"

class Map
{

public:

	Map();
	~Map();

	void loadMap(int arr[Game::levelSizeY][Game::levelSizeX]);
	void drawMap();

private:

	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

};