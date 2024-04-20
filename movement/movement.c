#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "movement.h"
#include "../map/map.h"
#include "../points/points.h"

void addScoredPoints(int *pointsScored, int value)
{
    *pointsScored += value;
}

void initializeMergedArray(bool **merged, int size)
{
    *merged = (bool *)calloc(size, sizeof(bool));
}

void freeMergedArray(bool *merged)
{
    free(merged);
}

void moveToTheLeft(int map[MAP_ROWS][MAP_COLS], bool *moveHasBeenMade, int *pointsScored)
{
    for (int i = 0; i < MAP_ROWS; i++)
    {
        int targetIndex = 0;
        bool *merged;
        initializeMergedArray(&merged, MAP_COLS);
        for (int j = 0; j < MAP_COLS; j++)
        {
            if (map[i][j] != 0)
            {
                if (targetIndex > 0 && map[i][targetIndex - 1] == map[i][j] && !merged[targetIndex - 1])
                {
                    map[i][targetIndex - 1] *= 2;
                    map[i][j] = 0;
                    merged[targetIndex - 1] = true;
                    *moveHasBeenMade = true;
                    addScoredPoints(pointsScored, map[i][targetIndex - 1]);
                }
                else
                {
                    if (targetIndex != j)
                    {
                        map[i][targetIndex] = map[i][j];
                        map[i][j] = 0;
                        *moveHasBeenMade = true;
                    }
                    targetIndex++;
                }
            }
        }
        freeMergedArray(merged);
    }
}

void moveToTheRight(int map[MAP_ROWS][MAP_COLS], bool *moveHasBeenMade, int *pointsScored)
{
    for (int i = 0; i < MAP_ROWS; i++)
    {
        int targetIndex = MAP_COLS - 1;
        bool *merged;
        initializeMergedArray(&merged, MAP_COLS);
        for (int j = MAP_COLS - 1; j >= 0; j--)
        {
            if (map[i][j] != 0)
            {
                if (targetIndex < MAP_COLS - 1 && map[i][targetIndex + 1] == map[i][j] && !merged[targetIndex + 1])
                {
                    map[i][targetIndex + 1] *= 2;
                    map[i][j] = 0;
                    merged[targetIndex + 1] = true;
                    *moveHasBeenMade = true;
                    addScoredPoints(pointsScored, map[i][targetIndex + 1]);
                }
                else
                {
                    if (targetIndex != j)
                    {
                        map[i][targetIndex] = map[i][j];
                        map[i][j] = 0;
                        *moveHasBeenMade = true;
                    }
                    targetIndex--;
                }
            }
        }
        freeMergedArray(merged);
    }
}

void moveToTheUp(int map[MAP_ROWS][MAP_COLS], bool *moveHasBeenMade, int *pointsScored)
{
    for (int j = 0; j < MAP_COLS; j++)
    {
        int targetIndex = 0;
        bool *merged;
        initializeMergedArray(&merged, MAP_COLS);
        for (int i = 0; i < MAP_ROWS; i++)
        {
            if (map[i][j] != 0)
            {
                if (targetIndex > 0 && map[targetIndex - 1][j] == map[i][j] && !merged[targetIndex - 1])
                {
                    map[targetIndex - 1][j] *= 2;
                    map[i][j] = 0;
                    merged[targetIndex - 1] = true;
                    *moveHasBeenMade = true;
                    addScoredPoints(pointsScored, map[targetIndex - 1][j]);
                }
                else
                {
                    if (targetIndex != i)
                    {
                        map[targetIndex][j] = map[i][j];
                        map[i][j] = 0;
                        *moveHasBeenMade = true;
                    }
                    targetIndex++;
                }
            }
        }
        freeMergedArray(merged);
    }
}

void moveToTheDown(int map[MAP_ROWS][MAP_COLS], bool *moveHasBeenMade, int *pointsScored)
{
    for (int j = 0; j < MAP_COLS; j++)
    {
        int targetIndex = MAP_ROWS - 1;
        bool *merged;
        initializeMergedArray(&merged, MAP_COLS);
        for (int i = MAP_ROWS - 1; i >= 0; i--)
        {
            if (map[i][j] != 0)
            {
                if (targetIndex < MAP_ROWS - 1 && map[targetIndex + 1][j] == map[i][j] && !merged[targetIndex + 1])
                {
                    map[targetIndex + 1][j] *= 2;
                    map[i][j] = 0;
                    merged[targetIndex + 1] = true;
                    *moveHasBeenMade = true;
                    addScoredPoints(pointsScored, map[targetIndex + 1][j]);
                }
                else
                {
                    if (targetIndex != i)
                    {
                        map[targetIndex][j] = map[i][j];
                        map[i][j] = 0;
                        *moveHasBeenMade = true;
                    }
                    targetIndex--;
                }
            }
        }
        freeMergedArray(merged);
    }
}

void move(int map[MAP_ROWS][MAP_COLS], char direction, bool *moveHasBeenMade, int *pointsScored)
{
    *moveHasBeenMade = false;

    switch (direction)
    {
    case 'a':
        moveToTheLeft(map, moveHasBeenMade, pointsScored);
        break;

    case 'd':
        moveToTheRight(map, moveHasBeenMade, pointsScored);
        break;

    case 'w':
        moveToTheUp(map, moveHasBeenMade, pointsScored);
        break;

    case 's':
        moveToTheDown(map, moveHasBeenMade, pointsScored);
        break;

    default:
        printf("Niedozwolony ruch\n");
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