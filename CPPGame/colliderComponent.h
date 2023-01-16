#pragma once
#include <string>
#include "SDL.h"
#include "components.h"

class ColliderComponent : public Component
{
public:

	SDL_Rect collider;
	std::string tag;

	TransformComponent* transform;

	void init() override
	{
		/*
		 HAS COMPONENT = BAD
		if (!entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}

		*/
		transform = &entity->getComponent<TransformComponent>();
	}

	ColliderComponent(std::string t)
	{
		tag = t;
	}
	
	void update() override
	{

		

		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);

		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;

		std::cout << "C.X: " << collider.x << " C.Y: " << collider.y << " C.W: " << collider.w << " C.H: " << collider.h << std::endl;
	}

};