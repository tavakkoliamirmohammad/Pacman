#ifndef PACMAN_GAME_PACMAN_H
#define PACMAN_GAME_PACMAN_H


#include "Component.h"
#include "Movable.h"

class Pacman : public Component, public Movable {
public:

    Pacman(Component *parent);

    void load(int time);

    void update(int time);

    void render(int time);

    void up(int time);

    void down(int time);

    void left(int time);

    void right(int time);

    void stop(int time);


private:

    GLuint texture_id;
    int frame;

    bool is_run = false;
};

#endif //PACMAN_GAME_PACMAN_H
