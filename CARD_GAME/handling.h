#ifndef _HANDLING_
#define _HANDLING_
#define SUITS 4
#define FACES 13

void shuffleCards(int deck[][FACES]);
void printCardsShuffling(int deck[][FACES], const char* suits[], const char* faces[]);
int** dealingForHand(int deck[][FACES]);
void printHand(int** hand, const char* suits[], const char* faces[], int deck[][FACES]);
int** createHandTest(int deck[SUITS][FACES], int a[]);
int getHighestCard(int** hand);


#endif // !_HANDLING_