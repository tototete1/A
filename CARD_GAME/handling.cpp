#include "Check.h"
#include "handling.h"
#include <ctime>
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;
void shuffleCards(int deck[][FACES])
{
    unsigned int seed = time(0);
    srand(seed);
    for (int i = 0; i < SUITS; i++)
    {
        for (int j = 0; j < FACES; j++)
        {
            deck[i][j] = 0;
        }
    }
    int d[53];
    memset(d, 0, sizeof(d));
    for (int i = 0; i < SUITS; i++)
    {
        for (int j = 0; j < FACES; j++)
        {
            int t = rand() % 52 + 1;
            while (d[t] == 1)
            {
                t = rand() % 52 + 1;
            }
            d[t] = 1;
            deck[i][j] = t;
        }
    }
}
void printCardsShuffling(int deck[][FACES], const char* suits[], const char* faces[])
{
    for (int i = 0; i < SUITS; i++)
    {
        for (int j = 0; j < FACES; j++)
        {
            cout << "(" << suits[i] << "," << faces[j] << "): " << deck[i][j] << endl;
        }
        cout << endl;
    }
}

int** dealingForHand(int deck[][FACES])
{
    static int* result[6];
    

    srand(time(NULL));
    int d[53];
    int x[4][14] = { 0 };
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= 5; i++)
    {
        result[i] = new int[2];
        int row, col;
        do {
            row = rand() % 4;
            col = rand() % 13;
        } while (x[row][col] != 0);
        result[i][0] = row;
        result[i][1] = col;
    }
    return result;

}

void printHand(int** hand, const char* suits[], const char* faces[], int deck[][FACES])
{

    for (int i = 1; i <= 5; i++) {
        cout << hand[i][0] << " " << hand[i][1] << endl;;
        int row = hand[i][0];
        int col = hand[i][1];
        cout << suits[row] << " " << faces[col] << endl;
    }
}

int** createHandTest(int deck[SUITS][FACES], int a[])
{
    static int* result[6];
    

    srand(time(NULL));
    int d[53];
    int x[4][14] = { 0 };
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= 5; i++)
    {
        result[i] = new int[2];
        int row, col;
        do {
            row = rand() % 4;
            col = rand() % 13;
        } while (x[row][col] != 0);
        result[i][0] = row;
        result[i][1] = col;
    }
    return result;
}

int getHighestCard(int** hand)
{
    if (isStraightFlush(hand ) == 1) return 8;
    if (isFourOfAKind(hand) == 1) return 7;
    if (isFullHouse(hand) == 1) return 6;
    if (isFlush(hand) == 1) return 5;
    if (isStraight(hand) == 1) return 4;
    if (isThreeOfAKind(hand) == 1) return 3;
    if (isTwoPairs(hand) == 1) return 2;
    if (isPair(hand) == 1) return 1;
    return 0;

}

