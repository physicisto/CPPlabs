#pragma once
#include "Card.h"
class Deck { //������
	Card deck[52];
public:
	int nDecks;
	Deck();
	~Deck();
	Card getCard(int i);
};

