#include <stdio.h>
#include <stdbool.h>
#include "movement.h"
#include "../map/map.h"
#include "../points/points.h"

void moveToTheLeft(int map[MAP_ROWS][MAP_COLS])
{
    for (int i = 0; i < MAP_ROWS; i++)
    {
        int targetIndex = 0;
        for (int j = 0; j < MAP_COLS; j++)
        {
            if (map[i][j] != 0)
            {
                if (targetIndex > 0 && map[i][targetIndex - 1] == map[i][j])
                {
                    map[i][targetIndex - 1] *= 2;
                    map[i][j] = 0;
                }
                else
                {
                    if (targetIndex != j)
                    {
                        map[i][targetIndex] = map[i][j];
                        map[i][j] = 0;
                    }
                    targetIndex++;
                }
            }
        }
    }
}

void moveToTheRight(int map[MAP_ROWS][MAP_COLS])
{
    for (int i = 0; i < MAP_ROWS; i++)
    {
        int targetIndex = MAP_COLS - 1;
        for (int j = MAP_COLS - 1; j >= 0; j--)
        {
            if (map[i][j] != 0)
            {
                if (targetIndex < MAP_COLS - 1 && map[i][targetIndex + 1] == map[i][j])
                {
                    map[i][targetIndex + 1] *= 2;
                    map[i][j] = 0;
                }
                else
                {
                    if (targetIndex != j)
                    {
                        map[i][targetIndex] = map[i][j];
                        map[i][j] = 0;
                    }
                    targetIndex--;
                }
            }
        }
    }
}

void moveToTheUp(int map[MAP_ROWS][MAP_COLS])
{
    for (int j = 0; j < MAP_COLS; j++)
    {
        int targetIndex = 0;
        for (int i = 0; i < MAP_ROWS; i++)
        {
            if (map[i][j] != 0)
            {
                if (targetIndex > 0 && map[targetIndex - 1][j] == map[i][j])
                {
                    map[targetIndex - 1][j] *= 2;
                    map[i][j] = 0;
                }
                else
                {
                    if (targetIndex != i)
                    {
                        map[targetIndex][j] = map[i][j];
                        map[i][j] = 0;
                    }
                    targetIndex++;
                }
            }
        }
    }
}

void moveToTheDown(int map[MAP_ROWS][MAP_COLS])
{
    for (int j = 0; j < MAP_COLS; j++)
    {
        int targetIndex = MAP_ROWS - 1;
        for (int i = MAP_ROWS - 1; i >= 0; i--)
        {
            if (map[i][j] != 0)
            {
                if (targetIndex < MAP_ROWS - 1 && map[targetIndex + 1][j] == map[i][j])
                {
                    map[targetIndex + 1][j] *= 2;
                    map[i][j] = 0;
                }
                else
                {
                    if (targetIndex != i)
                    {
                        map[targetIndex][j] = map[i][j];
                        map[i][j] = 0;
                    }
                    targetIndex--;
                }
            }
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