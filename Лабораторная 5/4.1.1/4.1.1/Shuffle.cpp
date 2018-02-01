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
		cout << "���� ������?" << endl;
		cin >> n;
		if (!(good = cin.good()))
			cout << "������ ������ ���� ������������� ������!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!good);
	try {
		if (n <= 0)
			throw 1;
	}
	catch (int) {
		cout << "������ ������ ���� �������������!" << endl;
		goto beginGame;
	}
	player->setBet(n);
	dealer->setBet(n);
	srand(time(0));
	//������ 1 ����� �������
	int d = rand() % 4;
	decks[d]->nDecks--;
	dealer->takeCard();
	//������ 2 ���� �������
	for (int i = 0; i < 2; i++) {
		int d = rand() % 4;
		decks[d]->nDecks--;
		player->takeCard();
	}
	cout << endl << "������: [" << decks[0]->nDecks << "] [" << decks[1]->nDecks << "] [" << decks[2]->nDecks << "] [" << decks[3]->nDecks << "] " << endl;
	cout << "�����:  ";
	dealer->Print();
	cout << "��:     ";
	player->Print();
	//----------------------------------------------------------------------------------------------------------------------------------
	//������
dialog:
	int dialogResult;
	cout << "1. ������ \n2. ���\n";
	cin >> dialogResult;
	if (dialogResult == 1) {  //���� ������
		int d = rand() % 4;
		decks[d]->nDecks--;
		dealer->takeCard();
		cout << endl << "������: [" << decks[0]->nDecks << "] [" << decks[1]->nDecks << "] [" << decks[2]->nDecks << "] [" << decks[3]->nDecks << "] " << endl;
		cout << "�����:  ";
		dealer->Print();
		cout << "��:     ";
		player->Print();
		if (player->compute() > 21) {
			cout << "�������. �� ���������." << endl;
			return;
		}
		else if (player->compute() > dealer->compute()) {
			player->setBet(n);
			cout << "�� ��������! ��� ����: " << player->getBank() << endl;
			return;
		}
		else if (player->compute() == dealer->compute()) {
			cout << "�����." << endl;
			return;
		}
		else if (player->compute() < dealer->compute()) {
			cout << "�� ���������." << endl;
			return;
		}
	}
		else if (dialogResult == 2) { // ���� �� ������
			int d = rand() % 4;
			decks[d]->nDecks--;
			player->takeCard();
			cout << endl << "������: [" << decks[0]->nDecks << "] [" << decks[1]->nDecks << "] [" << decks[2]->nDecks << "] [" << decks[3]->nDecks << "] " << endl;
			cout << "�����:  ";
			dealer->Print();
			cout << "��:     ";
			player->Print(); 
			if (player->compute() > 21) {
				cout << "�������. �� ���������." << endl;
				return;
			}
		dialog2:
			cout << "1. ������ \n2. ����\n";
			cin >> dialogResult;
			if (dialogResult == 1) { //���� ������ ����� �� ������
				int d = rand() % 4;
				decks[d]->nDecks--;
				dealer->takeCard();
				cout << endl << "������: [" << decks[0]->nDecks << "] [" << decks[1]->nDecks << "] [" << decks[2]->nDecks << "] [" << decks[3]->nDecks << "] " << endl;
				cout << "�����:  ";
				dealer->Print();
				cout << "��:     ";
				player->Print();
				if (player->compute() > 21) {
					cout << "�������. �� ���������." << endl;
					return;
				}
				else if (player->compute() > dealer->compute()) {
					player->setBet(n);
					cout << "�� ��������! ��� ����: " << player->getBank() << endl;
					return;
				}
				else if (player->compute() == dealer->compute()) {
					cout << "�����." << endl;
					return;
				}
				else if (player->compute() < dealer->compute()) {
					cout << "�� ���������." << endl;
					return;
				}
			}
			else if (dialogResult == 2) { //���� ����
				int d = rand() % 4;
				decks[d]->nDecks--;
				player->takeCard();
				int d2 = rand() % 4;
				decks[d2]->nDecks--;
				dealer->takeCard();
				player->setBet(n);
				dealer->setBet(n); 
				cout << endl << "������: [" << decks[0]->nDecks << "] [" << decks[1]->nDecks << "] [" << decks[2]->nDecks << "] [" << decks[3]->nDecks << "] " << endl;
				cout << "�����:  ";
				dealer->Print();
				cout << "��:     ";
				player->Print();
				if (player->compute() > 21) {
					cout << "�������. �� ���������." << endl;
					return;
				}
				else if (player->compute() > dealer->compute()) {
					player->setBet(n);
					cout << "�� ��������! ��� ����: " << player->getBank() << endl;
					return;
				}
				else if (player->compute() == dealer->compute()) {
					cout << "�����." << endl;
					return;
				}
				else if (player->compute() < dealer->compute()) {
					cout << "�� ���������." << endl;
					return;
				}
			}
		}
		else {
			cout << "�������� ������������ �������!" << endl;
			goto dialog;
		}
		cout << endl << "������: [" << decks[0]->nDecks << "] [" << decks[1]->nDecks << "] [" << decks[2]->nDecks << "] [" << decks[3]->nDecks << "] " << endl;
		cout << "�����:  ";
		dealer->Print();
		cout << "��:     ";
		player->Print();
	
	


}
Shuffle::~Shuffle() {
	delete player;
	delete dealer;
	//delete[] decks;
}