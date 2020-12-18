#include "Map.h"

bool Map::isBlocked(float x, float y) {
    return map[24 - (int)y / 40][(int)x / 40] == 'B';
}
