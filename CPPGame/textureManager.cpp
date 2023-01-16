#include "textureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* texture)
{

	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;

}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect srcPos, SDL_Rect srcDest)
{
	SDL_RenderCopy(Game::renderer, texture, &srcPos, &srcDest);
}