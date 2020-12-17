#pragma once
#include "Component.h"

class MainCharacter : public Component
{
public:

	enum CharacterDirection
	{
		None = 0, Up = 1, Right = 2, Down = 3, Left = 4
	};

	MainCharacter(Component* parent);
	void Load(int time);
	void Update(int time);
	void Render(int time);
	void SetPosition(int x, int y);

	void up(int time);
	void down(int time);
	void left(int time);
	void right(int time);
	void stop(int time);

private:
	float x; float y;
	GLuint texture_id;
	int frame;

	int start_move_time;
	CharacterDirection direction;
	bool is_run;
};