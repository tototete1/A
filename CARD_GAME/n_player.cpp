#include "n_player.h"
#include "Check.h"
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
using namespace std;

int*** dealingForHands(int deck[SUITS][FACES], int n) {

	int*** result = new int** [15];
	srand(time(NULL));
	int d[53];
	int x[4][13] = { 0 };
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++) {
		result[i] = new int* [6];
		for (int j = 1; j <= 5; j++) {
			result[i][j] = new int[2];
			int row, col;
			do {
				row = rand() % 4;
				col = rand() % 13;
			} while (x[row][col] != 0);
			result[i][j][0] = row;
			result[i][j][1] = col;

		}
	}
	return result;

}

int getStatusOfHand(int** hand) {
	if (isStraightFlush(hand) == 1) return 8;
	if (isFourOfAKind(hand) == 1) return 7;
	if (isFullHouse(hand) == 1) return 6;
	if (isFlush(hand) == 1) return 5;
	if (isStraight(hand) == 1) return 4;
	if (isThreeOfAKind(hand) == 1) return 3;
	if (isTwoPairs(hand) == 1) return 2;
	if (isPair(hand) == 1) return 1;
	return 0;
}

int* rankingHands(int*** hands, int n) {
	int* result[15];
	int* a = new int[15];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			result[j] = new int[2];
			result[j][0] = hands[i][j][0];
			result[j][1] = hands[i][j][1];
		}
		a[i] = getStatusOfHand(result);
	}
	return a;
}

int* evaluateHands(int* a,int *b,int n) {
	for (int i = 1; i <= n; i++) {
		b[i] = b[i] + a[i];
	}
	return b;
}
