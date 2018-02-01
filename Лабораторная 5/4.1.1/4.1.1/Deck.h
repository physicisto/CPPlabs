#pragma once
#include <vector>
#include "Card.h"
using namespace std;
class Deck { //колода
	vector<Card> deck[52];
public:
	int nDecks;
	Deck();
	~Deck();
	Card getCard(int i);
};

