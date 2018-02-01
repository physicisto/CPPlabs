#include "Player.h"
#include <random>
using namespace std;
#include<iostream>



Player::Player() {
	bank = 0;
}
void Player::setBet(int b) {
	bank += b;
}
void Player::takeCard() {
	random_device rand;
	mt19937 gen(rand());
	uniform_int_distribution<> dist(2, 14);
	int v = dist(gen);
	random_device rand2;
	mt19937 gen2(rand2());
	uniform_int_distribution<> dist2(0, 3);
	int s = dist2(gen2);
	flipper.setCard(v, s);
}
int Player::compute() {
	int nRet = 0;
		for (int i = 0; i < flipper.nCards; i++) {
			if (flipper.getCard(i + 1).getValue()>10) {
				nRet += 10;
				continue;
			}
			nRet += flipper.getCard(i + 1).getValue();
		}
		return nRet;
}

void Player::Print() {
	for (int i = 0; i <= getFlipper().nCards; i++) {
		cout << getFlipper().getCard(i) << " ";
	}
	cout << endl;
}
Player::~Player()
{
}
