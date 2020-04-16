#include "Entity.h"


Entity::Entity()
{
	is_alive = false;
}
Entity::~Entity()
{
}
void Entity::Init(int posx, int posy, int w, int h, int s)
{
	x = posx;
	y = posy;
	width = w;
	height = h;
	speed = s;
	is_alive = true;
}
void Entity::GetRect(int* posx, int* posy, int* w, int* h)
{
	*posx = x;
	*posy = y;
	*w = width;
	*h = height;
}
int Entity::GetX()
{
	return x;
}
void Entity::SwapState()
{
	if (is_alive == true) {
		is_alive = false;
	}
	else if (is_alive == false) {
		is_alive = true;
	}
}
bool Entity::IsAlive()
{
	return is_alive;
}

void Entity::Move(int dx, int dy)
{
	x += dx * speed;
	y += dy * speed;
}