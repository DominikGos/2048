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

void showMap(int map[MAP_COLS][MAP_ROWS], int* pointsScored)
{
    printf("\n");
    printf("Twoj wynik: %d\n\n", *pointsScored);

    for (int i = 0; i < MAP_ROWS; i++)
    {
        for (int j = 0; j < MAP_COLS; j++)
        {
            printf("\t");
            
            if(map[i][j] != 0) {
                printf("%d", map[i][j]);
            } else {
                printf("-");
            }
        }

        printf("\n");
    }

    printf("\n");
}