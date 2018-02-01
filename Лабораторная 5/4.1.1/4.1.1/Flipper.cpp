#include "Flipper.h"



Flipper::Flipper() {
	nCards = 0;
}
void Flipper::setCard(int v, int s) {
	Card c(v, s);
	flipper[nCards] = c;
	nCards++;
}
Card Flipper::getCard(int i) {
	return flipper[i - 1];
}


Flipper::~Flipper()
{
}
