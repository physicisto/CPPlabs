#pragma once
#include "Player.h"
class Dealer :
	public Player
{
public:
	Dealer();
	~Dealer();
	Flipper getFlipper() {
		return flipper;
	}
};

