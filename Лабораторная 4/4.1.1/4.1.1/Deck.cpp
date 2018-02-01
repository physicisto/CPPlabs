#include "Deck.h"
#include <iostream>
using namespace std;


Deck::Deck() {
	nDecks = 52;
	int i = 0;
	for (int s = 0; s < 4; s++) {
		for (int v = 2; v < 15; v++) {
			Card c(v, s);
			deck[i] = c;
			i++;
		}			
	}
}
Card Deck::getCard(int i) {
	return deck[i];
}
Deck::~Deck()
{
}
