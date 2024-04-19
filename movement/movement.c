#include <stdio.h>
#include <stdbool.h>
#include "movement.h"
#include "../map/map.h"

void moveToTheLeft(int map[MAP_ROWS][MAP_COLS]) {
    for (int i = 0; i < MAP_ROWS; i++) {
        int targetIndex = 0;
        for (int j = 0; j < MAP_COLS; j++) {
            if (map[i][j] != 0) {
                map[i][targetIndex++] = map[i][j];
            }
        }
        for (int j = targetIndex; j < MAP_COLS; j++) {
            map[i][j] = 0;
        }
    }
}

void moveToTheRight(int map[MAP_ROWS][MAP_COLS]) {
    for (int i = 0; i < MAP_ROWS; i++) {
        int targetIndex = MAP_COLS - 1;
        for (int j = MAP_COLS - 1; j >= 0; j--) {
            if (map[i][j] != 0) {
                map[i][targetIndex--] = map[i][j];
            }
        }
        for (int j = targetIndex; j >= 0; j--) {
            map[i][j] = 0;
        }
    }
}

void moveToTheUp(int map[MAP_ROWS][MAP_COLS]) {
    for (int j = 0; j < MAP_COLS; j++) {
        int targetIndex = 0;
        for (int i = 0; i < MAP_ROWS; i++) {
            if (map[i][j] != 0) {
                map[targetIndex++][j] = map[i][j];
            }
        }
        for (int i = targetIndex; i < MAP_ROWS; i++) {
            map[i][j] = 0;
        }
    }
}

void moveToTheDown(int map[MAP_ROWS][MAP_COLS]) {
    for (int j = 0; j < MAP_COLS; j++) {
        int targetIndex = MAP_ROWS - 1;
        for (int i = MAP_ROWS - 1; i >= 0; i--) {
            if (map[i][j] != 0) {
                map[targetIndex--][j] = map[i][j];
            }
        }
        for (int i = targetIndex; i >= 0; i--) {
            map[i][j] = 0;
        }
    }
}

void move(int map[MAP_ROWS][MAP_COLS], char direction)
{
    switch (direction)
    {
    case 'a':
        moveToTheLeft(map);
        break;

    case 'd':
        moveToTheRight(map);
        break;

    case 'w':
        moveToTheUp(map);
        break;

    case 's':
        moveToTheDown(map);
        break;

    default:
        printf("Invalid direction\n");
    }
}

bool userMoveIsValidated(char userMove)
{
    char availableKeys[] = {'a', 'w', 's', 'd', 'A', 'W', 'S', 'D'};
    bool moveIsCorrect = false;

    for (unsigned int i = 0; i < sizeof(availableKeys) / sizeof(availableKeys[0]); i++)
    {
        if (userMove == availableKeys[i])
        {
            moveIsCorrect = true;
            break;
        }
    }

    return moveIsCorrect;
}