#include <iostream>
#include "Shuffle.h"
using namespace std;


void main() {
	setlocale(LC_ALL, "RUSSIAN");
game:
	Shuffle shufle;
	shufle.Play();
	int dialogResult;
	cout << endl << "1. ������ ��� \n2. ������\n";
	cin >> dialogResult;
	if (dialogResult == 1) {
		goto game;
	}
	else
		return;
}
