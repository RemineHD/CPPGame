#ifndef game_hpp
#define game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include <iostream>

class ColliderComponent;

class Game {

public:

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	static const int levelSizeX = 16;
	static const int levelSizeY = 9;
	
	void handleEvents();
	void update();
	void render();
	void clean();

	static void addTile(int id, int x, int y);
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static std::vector<ColliderComponent*> colliders;
		

	bool running() { return isRunning; };

private:

	bool isRunning;
	int count = 0;
	SDL_Window* window;

};


#endif
