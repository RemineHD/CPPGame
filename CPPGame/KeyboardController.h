#pragma once

#include "game.h"
#include "components.h"

class KeyboardController : public Component
{

public:
	TransformComponent* tranform;

	void init() override 
	{
		tranform = &entity->getComponent<TransformComponent>();
	}

	void update() override
	{

		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				tranform->velocity.y = -1;
				break;
			case SDLK_a:
				tranform->velocity.x = -1;
				break;
			case SDLK_d:
				tranform->velocity.x = 1;
				break;
			case SDLK_s:
				tranform->velocity.y = 1;
			}
		}

		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				tranform->velocity.y = 0;
				break;
			case SDLK_a:
				tranform->velocity.x = 0;
				break;
			case SDLK_d:
				tranform->velocity.x = 0;
				break;
			case SDLK_s:
				tranform->velocity.y = 0;
			}
		}

	}


};