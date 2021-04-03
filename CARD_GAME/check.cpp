#include "Check.h"
#include <cstring>
#include <algorithm>
using namespace std;

bool isFourOfAKind(int** hand)
{
    //Tu quy
    int col, d[13];
    memset(d, 0, sizeof(d));

    for (int i = 1; i <= 5; i++) {
        col = hand[i][1];
        d[col]++;
        if (d[col] == 4) return true;
    }
    return false;
}

bool isFullHouse(int** hand)
{
    //Cu lu
    int col, d[13],u=0;
    memset(d, 0, sizeof(d));

    for (int i = 1; i <= 5; i++) {
        col = hand[i][1];
        d[col]++;
    }
    int z = 0;
    for (int i = 0; i <= 12; i++) {
        if (d[i] == 3) u++;
        if (d[i] == 2 && z==0) u++,z++;
    }
    return (u == 2);
}

bool isTwoPairs(int** hand)
{
    //Thu
    int col, u = 0, d[13];
    memset(d, 0, sizeof(d));

    for (int i = 1; i <= 5; i++) {
        col = hand[i][1];
        d[col]++;
        if (d[col] == 2) u++;
    }
    if (u == 2) return true;
    return false;
}

bool isPair(int** hand)
{
    //Doi
    int col, d[13];
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= 5; i++) {
        col = hand[i][1];
        d[col]++;
        if (d[col] == 2) return true;
    }
    return false;
}

bool isThreeOfAKind(int** hand)
{
    //Sam
    int d[13],col;
    memset(d, 0, sizeof(d));

    for (int i = 1; i <= 5; i++) {
        col = hand[i][1];
        d[col]++;
        if (d[col] == 3) return true;
    }
    return false;
}


bool isStraight(int** hand)
{
    //Sanh
    int col, d[6];
    memset(d, 0, sizeof(d));

    for (int i = 1; i <= 5; i++) {
        col = hand[i][1];
        d[i] = col;
    }
    sort(d + 1, d + 1 + 5);
    for (int i = 1; i < 5; i++) if (d[i] != d[i + 1] -1) return false;
    return true;
}

bool isFlush(int** hand)
{
    //Thung
    int u, row;
    for (int i = 1; i <= 5; i++) {
        row = hand[i][0];
        if (i == 1) u = row;
        else {
            if (u != row) return 0;
        }
    }
    return 1;
}

bool isStraightFlush(int** hand)
{
    //Thung sanh
    if (isFlush(hand) == 1 && isStraight(hand) == 1) return true;
    return false;
}