
#ifndef PACMAN_GAME_WALL_H
#define PACMAN_GAME_WALL_H

#include "Component.h"

using namespace std;

class Wall : public Component {
public:
    Wall(Component *parent);

    float getX();

    float getY();

    void load(int time);

    void update(int time);

    void render(int time);

    void setPosition(float x, float y, float angle);

private:
    float x, y;
    GLuint texture_id;
};

#endif //PACMAN_GAME_WALL_H
