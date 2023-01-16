#pragma once

#include "componets.h"
#include "SDL.h"

class SpriteComponent : public Component
{

private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTexture(path);
	}

	void setTexture(const char* path)
	{
		texture = TextureManager::loadTexture(path);
	}

	void init() override
	{

		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = srcRect.w * 5;
	}

	void update() override
	{

		destRect.x = (int) transform->position.x;
		destRect.y = (int) transform->position.y;

	}
	
	void draw() override
	{
		TextureManager::draw(texture, srcRect, destRect);
	}

};