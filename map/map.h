
#ifndef MAP_H
#define MAP_H

extern const int MAP_ROWS;
extern const int MAP_COLS;

extern void initializeMap(int map[MAP_COLS][MAP_ROWS]);
extern void showMap(int map[MAP_COLS][MAP_ROWS], int* pointsScored);
#endif 