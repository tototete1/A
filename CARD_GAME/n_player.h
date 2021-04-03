#ifndef _N_PLAYER_
#define _N_PLAYER_

#define SUITS 4
#define FACES 13

int*** dealingForHands(int deck[SUITS][FACES], int n);
int getStatusOfHand(int** hand);

#endif // !_N_PLAYER_
