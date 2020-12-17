#pragma once
#include <vector>
#include "Component.h"
#include "MainCharacter.h"

class Game: public Component
{
public:
	Game();
	~Game();

	void Load(int time);
	void Update(int time);
	void Render(int time);

	void keyboard(int time, int key, int x, int y);
	void keyboard_up(int time, int key, int x, int y);

private:

	MainCharacter* main_character;
	std::vector<Component*> components;
};