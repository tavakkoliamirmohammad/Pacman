

#ifndef PACMAN_GAME_SCORE_H
#define PACMAN_GAME_SCORE_H

#include "Component.h"

class Score : public Component {
public:
    Score(Component *parent);

    virtual void load(int time) = 0;

    void update(int time);

    void render(int time);

    void setPosition(float x, float y);

    int getScore();

    float getX() const;
    float getY() const;

protected:
    float x, y;
    int score;
    GLuint texture_id;
};

#endif //PACMAN_GAME_SCORE_H
