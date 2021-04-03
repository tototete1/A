#include "Check.h"
#include "handling.h"
#include "n_player.h"
#include <iostream>
using namespace std;

int main() {
    int deck[SUITS][FACES] = { 0 };
    const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const char* faces[FACES] = { "Two", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King","Ace" };
    
    //Cards shuffling & dealing

    /*shuffleCards(deck);
    printCardsShuffling(deck, suits, faces);
    */
    //1 player

    /*int** result;
    result = dealingForHand(deck);
    printHand(result, suits, faces, deck);
    cout << getHighestCard(result);*/
    int n;
    cin >> n;
    int*** result;
    result = dealingForHands(deck,n);
    for (int i = 1; i <= n; i++) {
        printHand(result[i], suits, faces, deck);
        cout << endl;
        cout << getStatusOfHand(result[i])<<endl;
    }
}