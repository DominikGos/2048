#ifndef POINTS_H
#define POINTS_H

#include "../map/map.h"

extern const int INITIAL_POINTS_NUMBER;
extern void initializePoints(int map[MAP_COLS][MAP_ROWS]);
extern void addPoint(int map[MAP_ROWS][MAP_COLS]);

struct Point
{
    int value;
    int row;
    int col;
};

#endif