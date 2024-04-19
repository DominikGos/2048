#include <stdio.h>
#include <stdbool.h>
#include "movement.h"
#include "../map/map.h"

void moveToLeft(int map[MAP_COLS][MAP_ROWS])
{
    for (int i = 0; i < MAP_ROWS; i++)
    {
        const int EMPTY_SPACE_IS_NOT_DEFINED = -1;
        int availableSpaceIndex = EMPTY_SPACE_IS_NOT_DEFINED;

        for (int j = 0; j < MAP_COLS; j++)
        {
            if (availableSpaceIndex == EMPTY_SPACE_IS_NOT_DEFINED && map[i][j] == 0)
            {
                availableSpaceIndex = j;
            }
        }

        printf("\n-------Available empty space index = %d\n", availableSpaceIndex);
    }
}

void move(int map[MAP_COLS][MAP_ROWS], char key)
{
    switch (key)
    {
    case 'a':
        moveToLeft(map);
        break;
    case 'w':
        printf("wwww");
        break;
    case 's':
        printf("sssssss");
        break;
    case 'd':
        printf("ddd");
        break;

    default:
        break;
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