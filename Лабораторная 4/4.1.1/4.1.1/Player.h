#pragma once
#include "Flipper.h"
class Player {
protected:
	Flipper flipper;	//рука
	int bank;			//ставка
public:
	Player();
	~Player();
	void setBet(int b);
	void takeCard();
	Flipper getFlipper() { return flipper; };
	int getBank() { return bank; };
	int compute();
	void Print();
};

