#ifndef PACMAN_GAME_GHOST_H
#define PACMAN_GAME_GHOST_H

#include "Component.h"

class Ghost : public Component {
public:

    enum CharacterDirection {
        None = 0, Up = 1, Right = 2, Down = 3, Left = 4
    };

    Ghost(Component *parent);

    void load(int time);

    void update(int time);

    void render(int time);

    void setPosition(int x, int y);

    float getX() const;

    float getY() const;


private:
    float x;
    float y;
    GLuint texture_id;
    int frame;

    int start_move_time;
    CharacterDirection direction;
};


#endif //PACMAN_GAME_GHOST_H
