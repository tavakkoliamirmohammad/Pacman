#pragma once
#include <stdlib.h>
#include <gl\glut.h>

class Game;

class Component
{
public:

	Component(Component* parent);
	void virtual Load(int time);
	void virtual Update(int time) = 0;
	void virtual Render(int time) = 0;

protected:

	int created_time;
	Game *game;
	Component *parent_component;
	friend class Game;
};