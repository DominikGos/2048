#include <stdio.h>
#include "map.h"

const int MAP_ROWS = 4;
const int MAP_COLS = 4;

void initializeMap(int map[MAP_COLS][MAP_ROWS])
{
    for (int i = 0; i < MAP_ROWS; i++)
    {
        for (int j = 0; j < MAP_COLS; j++)
        {
            map[i][j] = 0;
        }
    }
}

void showMap(int map[MAP_COLS][MAP_ROWS])
{
    printf("\n");

    for (int i = 0; i < MAP_ROWS; i++)
    {
        for (int j = 0; j < MAP_COLS; j++)
        {
            printf("\t%d", map[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}