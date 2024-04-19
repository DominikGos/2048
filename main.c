#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "map/map.h"
#include "points/points.h"

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
    char availableKeys[] = {'a', 'w', 's', 'd'};
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

int main()
{
    int map[MAP_COLS][MAP_ROWS], moveNumber = 0;
    bool running = true, userMoveIsCorrect, userMoveIsValidatedCorrectly;
    char userMove;

    srand(time(NULL));
    initializeMap(map);

    printf("\nWitaj w grze 2048!\nMozesz sie poruszac za pomoca klawiszy AWSD. Wybierz odpowiedni przycisk i zatwierdz.\n");

    while (running)
    {
        addPoints(map, moveNumber);
        showMap(map);
        moveNumber ++;

        do
        {
            printf("\nWybierz przycisk z AWSD: ");
            userMoveIsCorrect = scanf(" %c", &userMove);
            userMoveIsValidatedCorrectly = userMoveIsValidated(userMove);

            if(userMoveIsValidatedCorrectly != 1) continue;

            move(map, userMove); 
        } while (userMoveIsValidatedCorrectly != 1 || userMoveIsCorrect != 1);
    }
}