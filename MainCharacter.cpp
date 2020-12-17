#include "MainCharacter.h"
#include "SOIL.h"

MainCharacter::MainCharacter(Component * parent) : Component(parent)
{
}

void MainCharacter::Load(int time)
{
	Component::Load(time);

	texture_id = SOIL_load_OGL_texture("Sprites//sprite_main_character.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}

void MainCharacter::Update(int time)
{
	if (this->is_run) 
	{
		this->frame = (time - this->start_move_time) / 100;

		switch (this->direction)
		{
		case CharacterDirection::Up:
			this->y += .1;
			break;
		case CharacterDirection::Down:
			this->y -= .1;
			break;
		case CharacterDirection::Left:
			this->x -= .1;
			break;
		case CharacterDirection::Right:
		default:
			this->x += .1;
			break;
		}
	}
	else
	{
		this->frame = 0;
	}
}

void MainCharacter::Render(int time)
{
	auto f = (float)(this->frame % 12);

	auto tx_w = 1899.0 / 15.0;
	auto tx_h = 1390.0 / 5.0;
	auto tx_x = f / 12.0 + f * 0.001;
	auto tx_y = 3.0 / 4;

	switch (this->direction)
	{
	case CharacterDirection::Up:
		tx_y = 0.0 / 4;
		break;
	case CharacterDirection::Down:
		tx_y = 1.0 / 4;
		break;
	case CharacterDirection::Left:
		tx_y = 2.0 / 4;
		break;
	case CharacterDirection::Right:
	default:
		tx_y = 3.0 / 4;
		break;
	}

	glBindTexture(GL_TEXTURE_2D, texture_id);

	glPushMatrix();
	glTranslatef(this->x, this->y, 0);

	glBegin(GL_POLYGON);
	glTexCoord2f(tx_x, tx_y); glVertex2f(0, 0);
	glTexCoord2f(tx_x + 1.0 / 12.0 - 0.01, tx_y); glVertex2f(tx_w, 0);
	glTexCoord2f(tx_x + 1.0 / 12.0 - 0.01, tx_y + 1.0 / 4.0); glVertex2f(tx_w, tx_h);
	glTexCoord2f(tx_x, tx_y + 1.0 / 4.0); glVertex2f(0, tx_h);
	glEnd();

	glPopMatrix();
}

void MainCharacter::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void MainCharacter::up(int time)
{
	if (this->is_run && this->direction == CharacterDirection::Up) return;

	this->is_run = true;
	this->start_move_time = time;
	this->direction = CharacterDirection::Up;
}

void MainCharacter::down(int time)
{
	if (this->is_run && this->direction == CharacterDirection::Down) return;

	this->is_run = true;
	this->start_move_time = time;
	this->direction = CharacterDirection::Down;
}

void MainCharacter::left(int time)
{
	if (this->is_run && this->direction == CharacterDirection::Left) return;

	this->is_run = true;
	this->start_move_time = time;
	this->direction = CharacterDirection::Left;
}

void MainCharacter::right(int time)
{
	if (this->is_run && this->direction == CharacterDirection::Right) return;

	this->is_run = true;
	this->start_move_time = time;
	this->direction = CharacterDirection::Right;
}

void MainCharacter::stop(int time)
{
	this->is_run = false;
}
