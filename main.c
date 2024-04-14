#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAP_ROWS 4
#define MAP_COLS 4
#define INITIAL_POINTS_NUMBER 2

struct Point
{
    int value;
    int row;
    int col;
};

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
    struct Point point, availablePositions[MAP_ROWS * MAP_COLS];

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

void setPoints(int map[MAP_COLS][MAP_ROWS], int moveNumber)
{
    if (moveNumber == 0)
    {
        initializePoints(map);
       /*  struct Point p1 = {.row = 0, .col = 3, .value = 2};
        struct Point p2 = {.row = 0, .col = 2, .value = 4};
        map[p1.row][p1.col] = p1.value;
        map[p2.row][p2.col] = p1.value; */
        return;
    }

    struct Point p = generatePoint(map);

    map[p.row][p.col] = p.value;
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

    for (int i = 0; i < sizeof(availableKeys) / sizeof(availableKeys[0]); i++)
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
        setPoints(map, moveNumber);
        showMap(map);

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