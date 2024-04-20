#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "map/map.h"
#include "points/points.h"
#include "movement/movement.h"

int main()
{
    int map[MAP_COLS][MAP_ROWS], moveNumber = 0;
    bool running = true, userMoveIsCorrect, userMoveIsValidatedCorrectly;
    bool moveHasBeenMade;
    char userMove;

    srand(time(NULL));
    initializeMap(map);
    initializePoints(map);

    printf("\nWitaj w grze 2048!\nMozesz sie poruszac za pomoca klawiszy AWSD. Wybierz odpowiedni przycisk i zatwierdz.\n");

    while (running)
    {
        showMap(map);
        moveNumber ++;

        do
        {
            printf("\nWybierz przycisk z AWSD: ");
            userMoveIsCorrect = scanf(" %c", &userMove);
            userMoveIsValidatedCorrectly = userMoveIsValidated(userMove);

            if(userMoveIsValidatedCorrectly != 1) continue;

            move(map, userMove, &moveHasBeenMade); 
        } while (userMoveIsValidatedCorrectly != 1 || userMoveIsCorrect != 1);

        if(moveHasBeenMade)
            addPoint(map);
    }
}