#pragma once
#include "Card.h"
class Deck { //колода
	Card deck[52];
public:
	int nDecks;
	Deck();
	~Deck();
	Card getCard(int i);
};

