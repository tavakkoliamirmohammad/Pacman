#pragma once
#include "Component.h"

class Fire : public Component
{
public:
	Fire(Component* parent);
	void Load(int time);
	void Update(int time);
	void Render(int time);
	void SetPosition(int x, int y);
private:
	int x; int y;
	GLuint texture_id;
	int init_frame, frame;
};