#pragma once

#include "game.h"

class TextureManager {

public:
	static SDL_Texture* loadTexture (const char* fileName);
	static void draw(SDL_Texture* texture, SDL_Rect srcPos, SDL_Rect srcDest);

private:

};