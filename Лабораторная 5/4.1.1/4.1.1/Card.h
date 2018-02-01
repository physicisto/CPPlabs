#pragma once
#include <iostream>
using namespace std;
class Card {
	enum Value {
		_2 = 2,_3,_4,_5,_6,_7,_8,_9,_10,J,Q,K,A
	};
	enum Suit{
		heart, diamonds, club, spade
	};
	char nameValue;
	Value value;	//значение
	Suit suit;		//масть
public:
	Card();
	Card(int v, int s);
	virtual ~Card();
	int getValue();
	friend ostream& operator<< (ostream& o, Card card);
};

