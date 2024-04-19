#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "points.h"

const int INITIAL_POINTS_NUMBER = 2;

int generatePointValue()
{
    return ((rand() % 2) + 1) * 2;
}

void getAvailablePositions(int map[MAP_COLS][MAP_ROWS], struct Point availablePositions[], int *numberOfAvailablePositions)
{
    int index = 0;

    for (int i = 0; i < MAP_ROWS; i++)
    {
        for (int j = 0; j < MAP_COLS; j++)
        {
            if (map[i][j] == 0)
            {
                availablePositions[index].row = i;
                availablePositions[index].col = j;
                index++;
            }
        }
    }

    *numberOfAvailablePositions = index;
}

struct Point generatePoint(int map[MAP_ROWS][MAP_COLS])
{
    int randomIndex, numberOfAvailablePositions;
    struct Point availablePositions[MAP_ROWS * MAP_COLS];

    getAvailablePositions(map, availablePositions, &numberOfAvailablePositions);

    if (numberOfAvailablePositions == 0)
    {
        printf("\nThere is no any available points.\n");

        struct Point emptyPoint = {.value = -1, .row = -1, .col = -1};
        return emptyPoint;
    }

    randomIndex = rand() % numberOfAvailablePositions;
    availablePositions[randomIndex].value = generatePointValue();
    printf("\n row = %d col = %d value = %d\n", availablePositions[randomIndex].row, availablePositions[randomIndex].col, availablePositions[randomIndex].value);

    return availablePositions[randomIndex];
}

void initializePoints(int map[MAP_COLS][MAP_ROWS])
{
    for (int i = 0; i < INITIAL_POINTS_NUMBER; i++)
    {
        struct Point p = generatePoint(map);
        map[p.row][p.col] = p.value;
    }
}

void addPoints(int map[MAP_COLS][MAP_ROWS], int moveNumber)
{
    if (moveNumber == 0)
    {
        initializePoints(map);
   
        return;
    }

    struct Point p = generatePoint(map);

    map[p.row][p.col] = p.value;
}