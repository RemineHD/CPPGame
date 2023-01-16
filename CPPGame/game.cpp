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

auto& title0(manager.addEntity());
auto& title1(manager.addEntity());
auto& title2(manager.addEntity());

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

	title0.addComponent<TileComponent>(200, 200, 32, 32, 0);
	title1.addComponent<TileComponent>(500, 500, 32, 32, 1);
	title1.addComponent<ColliderComponent>("dirt");
	title2.addComponent<TileComponent>(800, 800, 32, 32, 2);
	title2.addComponent<ColliderComponent>("grass");

	player.addComponent<TransformComponent>(0, 0, 24, 23, 5);
	player.addComponent<KeyboardController>();
	player.addComponent<SpriteComponent>("assets/skeleton_idle.png");
	player.addComponent<ColliderComponent>("player");

	//wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 5);
	//wall.addComponent<SpriteComponent>("assets/grass.png");
	//wall.addComponent<ColliderComponent>("wall");

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
	//map->drawMap();
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