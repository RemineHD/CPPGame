#include "game.h"
#include "textureManager.h"
#include "map.h"

#include "ecs.h"
#include "components.h"
#include "collision.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;


auto& player(manager.addEntity());
auto& wall(manager.addEntity());

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

	map = new Map();

	Map::loadMap("assets/maps/level1.txt", 16, 16);

	player.addComponent<TransformComponent>(0, 0, 24, 23, 5);
	player.addComponent<KeyboardController>();
	player.addComponent<SpriteComponent>("assets/skeleton_idle.png");
	player.addComponent<ColliderComponent>("player");

}

void Game::handleEvents()
{

	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update()
{
	//player->update();
	//map->loadMap();

	manager.refresh();
	manager.update();

	for (auto cc : colliders)
	{
		if (Collision::AABB(player.getComponent<ColliderComponent>(), *cc))
		{
			player.getComponent<TransformComponent>().velocity * -1;
			std::cout << "Wall hit!" << std::endl;
		}
	}

}

void Game::render()
{

	SDL_RenderClear(renderer);
	manager.draw();
	SDL_RenderPresent(renderer);

}

void Game::clean()
{

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;

}

void Game::addTile(int id, int x, int y)
{

	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(x, y, 32, 32, id);

}