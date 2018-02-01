#include <iostream>
#include <stdio.h>
#include <iomanip> // ��� setw()
using namespace std;


void InitializeArray(int **mas);                      // ������������� 2D-�������
void PrintArray(int** mas, int* masTrans);            // ����� ��������
int Factorial(int i);                                 // ����������� ��������� - ��� �������������
int* TransformationArray(int **mas);                  // �������������� ������� 2D -> 1D

void main() {
	int ** mas = new int*[5]; // ���� ����� � �������
	for (int i = 0; i < 5; i++)
		*(mas + i) = new int[5]; // � ���� ��������
	InitializeArray(mas);
	int*  mas2 = TransformationArray(mas);
	PrintArray(mas, mas2);
	delete []mas2;
	for (int i = 0; i < 5; i++) {
		delete[]mas[i];
	}
	delete[]mas;
	
	system("pause");
}



void InitializeArray(int **mas) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			*(*(mas+i)+j) = Factorial(i+j);
		}
	}
}

void PrintArray(int** mas, int* masTrans) { 	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) 
			cout << setw(8)<< *(*(mas+i)+j);
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 15; i++){
		cout << setw(8) << *(masTrans + i);
	}
	cout << endl;
}

int* TransformationArray(int **mas) { 

	int* masTrans = new int[15];
	for (int i = 0; i < 5; i+=2) {
		for (int j = 0; j < 5; j++) {
			static int d = 0;           // "��� ��" ���������� ����������, �������� �����
			*(masTrans + d) = *(*(mas + i) + j);
			d++;
		}
		
	}
	return masTrans;
}

int Factorial(int i) {  //���������, ���������
	if (i == 0) {
		return 1;
	}
	else
	return i*Factorial(i-1);
	
}