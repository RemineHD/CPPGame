#include "gameObject.h"
#include "textureManager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* _renderer, int x, int y)
{

	renderer = _renderer;
	objTexture = TextureManager::loadTexture(texturesheet, _renderer);

	xpos = x;
	ypos = y;


}

void GameObject::update()
{
	xpos++;
	ypos++;


	srcRect.h = 500;
	srcRect.w = 500;
	srcRect.x = 0;
	srcRect.y = 0;
	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

}

void GameObject::render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);

}