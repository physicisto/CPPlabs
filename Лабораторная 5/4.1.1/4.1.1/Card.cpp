#include "Card.h"

Card::Card(){}

Card::Card(int v, int s) {
	value = Value(v);
	switch (value) {
	case 2:
		nameValue = '2';
		break;
	case 3:
		nameValue = '3';
		break;
	case 4:
		nameValue = '4';
		break;
	case 5:
		nameValue = '5';
		break;
	case 6:
		nameValue = '6';
		break;
	case 7:
		nameValue = '7';
		break;
	case 8:
		nameValue = '8';
		break;
	case 9:
		nameValue = '9';
		break;
	case 10:
		nameValue = 'D';
		break;
	case 11:
		nameValue = 'J';
		break;
	case 12:
		nameValue = 'Q';
		break;
	case 13:
		nameValue = 'K';
		break;
	case 14:
		nameValue = 'A';
		break;
	}
	suit = Suit(s);
}
int Card::getValue() {
	return value;
}
ostream& operator<< (ostream& o, Card card) {
	switch (card.suit) {
	case 0:
		o << card.nameValue << static_cast<char>(3);
		break;
	case 1:
		o << card.nameValue << static_cast<char>(4);
		break;
	case 2:
		o << card.nameValue << static_cast<char>(5);
		break;
	case 3:
		o << card.nameValue << static_cast<char>(6);
		break;
	}
	return o;
}
Card::~Card() {}