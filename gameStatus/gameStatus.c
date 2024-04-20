#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameStatus.h"

const int requiredPointsToWin = 256;

bool doesUserWonTheGame(int map[MAP_COLS][MAP_ROWS])
{
    for (int i = 0; i < MAP_ROWS; i++)
    {
        for (int j = 0; j < MAP_COLS; j++)
        {
            if (map[i][j] == requiredPointsToWin)
            {
                printf("\nGratulacje! Wygrales.\n");
                return true;
            }
        }
    }

    return false;
}

bool doesUserLostTheGame(int map[MAP_COLS][MAP_ROWS])
{
    for (int i = 0; i < MAP_ROWS; i++)
    {
        for (int j = 0; j < MAP_COLS; j++)
        {
            if (map[i][j] == 0) // user still has chance to win the game
                return false;
            if ((j + 1 < MAP_COLS) && map[i][j] == map[i][j + 1])
                return false;
        }
    }

    for (int j = 0; j < MAP_COLS; j++)
    {
        for (int i = 0; i < MAP_ROWS; i++)
        {
            if ((i + 1 < MAP_ROWS) && map[i][j] == map[i + 1][j])
                return false;
        }
    }

    printf("\nPregrales.\n");
    return true;
}