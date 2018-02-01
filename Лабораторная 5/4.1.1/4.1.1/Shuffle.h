#pragma once
#include "Dealer.h"
#include "Player.h"
#include "Deck.h"

class Shuffle {
	Player* player;
	Player* dealer;
	Deck* decks[4];
public:
	Shuffle();
	~Shuffle();
	void Play();
};