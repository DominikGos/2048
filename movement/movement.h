
#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../map/map.h"

extern bool userMoveIsValidated(char userMove);
extern void move(int map[MAP_COLS][MAP_ROWS], char key, bool* moveHasBeenMade);
#endif 