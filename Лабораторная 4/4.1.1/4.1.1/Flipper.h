#pragma once
#include "Card.h"
class Flipper {
	Card flipper[4];
public:
	int nCards;
	Flipper();
	~Flipper();
	void setCard(int v, int s);
	Card getCard(int i);
};

