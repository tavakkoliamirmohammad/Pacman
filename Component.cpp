#include "Component.h"

Component::Component(Component* parent)
{
	parent_component = parent;
	if (parent != NULL) game = parent->game;
	else game = NULL;
}

void Component::load(int time)
{
    created_time = time;
}
