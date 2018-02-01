#include "Shuffle.h"
#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include <ctime>
#include <iostream>
using namespace std;


Shuffle::Shuffle() {
	player = new Player;
	dealer = new Dealer;
	for (int i = 0; i < 4; i++) {
		decks[i] = new Deck;
	}
}
void Shuffle::Play() {
beginGame:
	int n;
	bool good = true;
	do
	{
		cout << "Ваша ставка?" << endl;
		cin >> n;
		if (!(good = cin.good()))
			cout << "Ставка должна быть положительным числом!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!good);
	try {
		if (n <= 0)
			throw 1;
	}
	catch (int) {
		cout << "Ставка должна быть положительной!" << endl;
		goto beginGame;
	}
	player->setBet(n);
	dealer->setBet(n);
	srand(time(0));
	//взятие 1 карты дилером
	int d = rand() % 4;
	decks[d]->nDecks--;
	dealer->takeCard();
	//взятие 2 карт игроком
	for (int i = 0; i < 2; i++) {
		int d = rand() % 4;
		decks[d]->nDecks--;
		player->takeCard();
	}
	cout << endl << "Колоды: [" << decks[0]->nDecks << "] [" << decks[1]->nDecks << "] [" << decks[2]->nDecks << "] [" << decks[3]->nDecks << "] " << endl;
	cout << "Дилер:  ";
	dealer->Print();
	cout << "Вы:     ";
	player->Print();
	//----------------------------------------------------------------------------------------------------------------------------------
	//диалог
dialog:
	int dialogResult;
	cout << "1. Хватит \n2. Еще\n";
	cin >> dialogResult;
	if (dialogResult == 1) {  //Если хватит
		int d = rand() % 4;
		decks[d]->nDecks--;
		dealer->takeCard();
		cout << endl << "Колоды: [" << decks[0]->nDecks << "] [" << decks[1]->nDecks << "] [" << decks[2]->nDecks << "] [" << decks[3]->nDecks << "] " << endl;
		cout << "Дилер:  ";
		dealer->Print();
		cout << "Вы:     ";
		player->Print();
		if (player->compute() > 21) {
			cout << "Перебор. Вы проиграли." << endl;
			return;
		}
		else if (player->compute() > dealer->compute()) {
			player->setBet(n);
			cout << "Вы выиграли! Ваш банк: " << player->getBank() << endl;
			return;
		}
		else if (player->compute() == dealer->compute()) {
			cout << "Ничья." << endl;
			return;
		}
		else if (player->compute() < dealer->compute()) {
			cout << "Вы проиграли." << endl;
			return;
		}
	}
		else if (dialogResult == 2) { // если не хватит
			int d = rand() % 4;
			decks[d]->nDecks--;
			player->takeCard();
			cout << endl << "Колоды: [" << decks[0]->nDecks << "] [" << decks[1]->nDecks << "] [" << decks[2]->nDecks << "] [" << decks[3]->nDecks << "] " << endl;
			cout << "Дилер:  ";
			dealer->Print();
			cout << "Вы:     ";
			player->Print(); 
			if (player->compute() > 21) {
				cout << "Перебор. Вы проиграли." << endl;
				return;
			}
		dialog2:
			cout << "1. Хватит \n2. Дабл\n";
			cin >> dialogResult;
			if (dialogResult == 1) { //если хватит после не хватит
				int d = rand() % 4;
				decks[d]->nDecks--;
				dealer->takeCard();
				cout << endl << "Колоды: [" << decks[0]->nDecks << "] [" << decks[1]->nDecks << "] [" << decks[2]->nDecks << "] [" << decks[3]->nDecks << "] " << endl;
				cout << "Дилер:  ";
				dealer->Print();
				cout << "Вы:     ";
				player->Print();
				if (player->compute() > 21) {
					cout << "Перебор. Вы проиграли." << endl;
					return;
				}
				else if (player->compute() > dealer->compute()) {
					player->setBet(n);
					cout << "Вы выиграли! Ваш банк: " << player->getBank() << endl;
					return;
				}
				else if (player->compute() == dealer->compute()) {
					cout << "Ничья." << endl;
					return;
				}
				else if (player->compute() < dealer->compute()) {
					cout << "Вы проиграли." << endl;
					return;
				}
			}
			else if (dialogResult == 2) { //если дабл
				int d = rand() % 4;
				decks[d]->nDecks--;
				player->takeCard();
				int d2 = rand() % 4;
				decks[d2]->nDecks--;
				dealer->takeCard();
				player->setBet(n);
				dealer->setBet(n); 
				cout << endl << "Колоды: [" << decks[0]->nDecks << "] [" << decks[1]->nDecks << "] [" << decks[2]->nDecks << "] [" << decks[3]->nDecks << "] " << endl;
				cout << "Дилер:  ";
				dealer->Print();
				cout << "Вы:     ";
				player->Print();
				if (player->compute() > 21) {
					cout << "Перебор. Вы проиграли." << endl;
					return;
				}
				else if (player->compute() > dealer->compute()) {
					player->setBet(n);
					cout << "Вы выиграли! Ваш банк: " << player->getBank() << endl;
					return;
				}
				else if (player->compute() == dealer->compute()) {
					cout << "Ничья." << endl;
					return;
				}
				else if (player->compute() < dealer->compute()) {
					cout << "Вы проиграли." << endl;
					return;
				}
			}
		}
		else {
			cout << "Выберите предложенный вариант!" << endl;
			goto dialog;
		}
		cout << endl << "Колоды: [" << decks[0]->nDecks << "] [" << decks[1]->nDecks << "] [" << decks[2]->nDecks << "] [" << decks[3]->nDecks << "] " << endl;
		cout << "Дилер:  ";
		dealer->Print();
		cout << "Вы:     ";
		player->Print();
	
	


}
Shuffle::~Shuffle() {
	delete player;
	delete dealer;
	//delete[] decks;
}