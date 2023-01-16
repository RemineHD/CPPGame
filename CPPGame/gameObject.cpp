#include "gameObject.h"
#include "textureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{

	objTexture = TextureManager::loadTexture(texturesheet);

	xpos = x;
	ypos = y;

}

void GameObject::update()
{
	//xpos++;
	//ypos++;


	srcRect.h = 35;
	srcRect.w = 35;
	srcRect.x = 0;
	srcRect.y = 0;
	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 5;
	destRect.h = srcRect.h * 5;

}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);

}