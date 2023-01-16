#pragma once

#include "components.h"
#include "Vector2D.h"

struct TransformComponent : public Component
{

	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;

	TransformComponent() { position.zero(); }

	TransformComponent(float x, float y) { setPos(x, y); }

	TransformComponent(float x, float y, int h, int w, int s) 
	{ 
		setPos(x, y);
		height = h;
		width = w;
		scale = s;
	}

	void setPos(float x, float y)
	{
		position.x = x;
		position.y = y;
	}
	
	void init() override
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

};