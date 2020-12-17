#include "Fire.h"
#include "SOIL.h"

Fire::Fire(Component *parent) : Component(parent) {
    init_frame = ((double) rand() / (RAND_MAX)) * 64;
}

void Fire::load(int time) {
    Component::load(time);

    texture_id = SOIL_load_OGL_texture("/home/amir/projects/pacman_game/Sprites/sprite_fire.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_INVERT_Y);
/*
	int tx_width, tx_height;

	auto tx_fire = SOIL_load_image("Sprites//sprite_fire.png", &tx_width, &tx_height, 0, SOIL_LOAD_RGBA);

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tx_width, tx_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tx_fire);

	SOIL_free_image_data(tx_fire);*/
}

void Fire::update(int time) {
    frame = init_frame + (time - created_time) / 50;
}

void Fire::render(int time) {
    auto w_h = (float) (frame % 8);
    auto w_v = (float) (int) ((frame % 64) / 8) + 1;

    auto tx_w = 1024.0 / 8.0;
    auto tx_h = 1024.0 / 8.0;
    auto tx_x = w_h / 8.0;
    auto tx_y = 1 - w_v / 8.0;

    glBindTexture(GL_TEXTURE_2D, texture_id);

    glPushMatrix();
    glTranslatef(this->x, this->y, 0);

    glBegin(GL_POLYGON);
    glTexCoord2f(tx_x, tx_y);
    glVertex2f(0, 0);
    glTexCoord2f(tx_x + 1.0 / 8.0, tx_y);
    glVertex2f(tx_w, 0);
    glTexCoord2f(tx_x + 1.0 / 8.0, tx_y + 1.0 / 8.0);
    glVertex2f(tx_w, tx_h);
    glTexCoord2f(tx_x, tx_y + 1.0 / 8.0);
    glVertex2f(0, tx_h);
    glEnd();

    glPopMatrix();
}

void Fire::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}
