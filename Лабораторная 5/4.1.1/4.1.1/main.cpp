#include <iostream>
#include <algorithm>
#include <vector>
#include "Shuffle.h"
using namespace std;
class myFind {
public:
	bool operator()(int x) {
		return x > 10;
	}
};

void main() {
	setlocale(LC_ALL, "RUSSIAN");
game:
	Shuffle shufle;
	shufle.Play();
	int dialogResult;
	cout << endl << "1. Играть еще \n2. Хватит\n";
	cin >> dialogResult;
	if (dialogResult == 1) {
		goto game;
	}
	else
		return;

	int ints[5] = { 1,2,2,30,40 };
	myFind f;
	find_if(0, 4, f);
}
