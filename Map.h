#ifndef PACMAN_GAME_MAP_H
#define PACMAN_GAME_MAP_H

class Map {
public:
    static bool isBlocked(float x, float y);

    static char map[25][25];

};

#endif //PACMAN_GAME_MAP_H
