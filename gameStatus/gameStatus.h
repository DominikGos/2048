
#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include "../map/map.h"

extern bool doesUserLostTheGame(int map[MAP_COLS][MAP_ROWS]);
extern bool doesUserWonTheGame(int map[MAP_COLS][MAP_ROWS]);
#endif 