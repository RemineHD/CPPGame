#pragma once

#include "componets.h"
#include "Vector2D.h"

struct TransformComponent : public Component
{

	Vector2D position;

	TransformComponent() { setPos(0.0f, 0.0f); }

	TransformComponent(int x, int y) { setPos(x, y); }

	void setPos(int x, int y)
	{
		position.x = x;
		position.y = y;
	}
	
	void update() override
	{
		//xpos++;
		//ypos++;
	}

};