#include "Game.h"
#include "Fire.h"
#include <typeinfo>

Game::Game() :Component(NULL)
{
	this->game = this;
}

Game::~Game()
{
}

void Game::Load(int time)
{
	this->main_character = new MainCharacter(this);
	this->main_character->SetPosition(500, 500);
	components.push_back(this->main_character);

	for (int i = 0; i < 20; i++)
	{
		Fire *fire = new Fire(this);
		fire->SetPosition(100 * i, 0);
		components.push_back(fire);

	}

/*
	Fire *fire_2 = new Fire(this);
	fire_2->SetPosition(100, 0);
	components.push_back(fire_2);*/

	for (auto iter = components.begin(); iter != components.end(); iter++)
		(*iter)->Load(time);
}

void Game::Update(int time)
{
	for (auto iter = components.begin(); iter != components.end(); iter++)
		(*iter)->Update(time);
}

void Game::Render(int time)
{
	for (auto iter = components.begin(); iter != components.end(); iter++)
		(*iter)->Render(time);
}

void Game::keyboard(int time, int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		this->main_character->up(time);
		break;
	case GLUT_KEY_DOWN:
		this->main_character->down(time);
		break;
	case GLUT_KEY_LEFT:
		this->main_character->left(time);
		break;
	case GLUT_KEY_RIGHT:
		this->main_character->right(time);
		break;
	}
}

void Game::keyboard_up(int time, int key, int x, int y)
{
	this->main_character->stop(time);
}
