#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "map/map.h"
#include "points/points.h"
#include "movement/movement.h"
#include "gameStatus/gameStatus.h"

int main()
{
    int map[MAP_COLS][MAP_ROWS], moveNumber = 0;
    bool running = true, userMoveIsCorrect, userMoveIsValidatedCorrectly, moveHasBeenMade;
    char userMove;

    srand(time(NULL));
    initializeMap(map);
    initializePoints(map);
    printf("\nWitaj w grze 2048!\nMozesz sie poruszac za pomoca klawiszy AWSD. Wybierz odpowiedni przycisk i zatwierdz.\n");
    showMap(map);

    while (running)
    {
        moveNumber++;

        if (doesUserLostTheGame(map))
        {
            exit(0);
        }

        do
        {
            printf("\nWybierz przycisk z AWSD: ");
            userMoveIsCorrect = scanf(" %c", &userMove);
            userMoveIsValidatedCorrectly = userMoveIsValidated(userMove);

            if (userMoveIsValidatedCorrectly != 1)
                continue;

            move(map, userMove, &moveHasBeenMade);
        } while (!userMoveIsValidatedCorrectly || !userMoveIsCorrect);

        if (doesUserWonTheGame(map))
        {
            showMap(map);
            exit(0);
        }

        if (moveHasBeenMade)
            addPoint(map);

        showMap(map);
    }
}