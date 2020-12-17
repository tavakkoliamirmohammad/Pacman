#pragma once

#include "Component.h"

class Fire : public Component {
public:
    Fire(Component *parent);

    void load(int time);

    void update(int time);

    void render(int time);

    void setPosition(int x, int y);

private:
    int x;
    int y;
    GLuint texture_id;
    int init_frame, frame;
};