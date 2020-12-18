#ifndef PACMAN_GAME_GHOST_H
#define PACMAN_GAME_GHOST_H

#include "Component.h"
#include "Movable.h"

class Ghost : public Component, public Movable {
public:

    Ghost(Component *parent);

    void load(int time);

    void update(int time);

    void render(int time);

    CharacterDirection nextDirectionBlocked();

    void up(int time);

    void down(int time);

    void left(int time);

    void right(int time);


private:
    GLuint texture_id;
    int frame;
};


#endif //PACMAN_GAME_GHOST_H
