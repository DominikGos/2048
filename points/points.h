#ifndef POINTS_H
#define POINTS_H

#include "../map/map.h"

extern const int INITIAL_POINTS_NUMBER;
extern void addPoints(int map[MAP_ROWS][MAP_COLS], int moveNumber);

struct Point
{
    int value;
    int row;
    int col;
};

#endif