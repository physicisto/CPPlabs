#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <ctime>       // ��� ��������� �����
using namespace std;

float processArray(float *item, float* mas, float* mas2); //������������� ����������, ��� ������ ����� ��� �������

void main() {

	//setlocale(LC_ALL, "RUSSIAN");
	float item;
	scanf_s( "%f", &item);
	float mas[18] = { 0 };
	float mas2[18] = { 0 };
	// ��������� �����
	srand(time(0));
	for (int i = 0; i < 18; i++) {
		float _rand = rand() % 70 - 20;
		mas[i] = _rand;
	}
	printf(" First array: \n");
	for (int i = 0; i < 18; i++) {
		printf("%f  ", mas[i]);
	}

	float max = processArray(&item, mas, mas2);
	printf("\n \n Max item: %f \n", max );


	printf("\n Norm array: \n\n");

	for (int i = 0; i < 18; i++) {
		printf("%f  ", mas[i]);
	}


	printf("\n\n New array: \n");

	for (int i = 0; i < 18; i++) {
		printf("%f  ", mas2[i] );
	}
	system("pause");

}

float processArray(float *item, float* mas, float* mas2) {
	// ����� ������������� �� ������ ��������
	int count = 0;
	float max = mas[0];
	for (int i = 0; i < 17; i++) {
		if (abs(max) < abs(mas[i + 1])) {
			max = mas[i + 1];
			count = i + 1;
		}
	}
	//��������� ��������������� ������
	for (int i = 0; i < 18; i++) {
		*(mas + i) /= max;        // mas[i] = mas[i] / max;

	}
	// ������� ������ � item��� ����� ������������� ��������
	for (int i = 0; i < 18; i++) {
		if (i <= count) {
			mas2[i] = mas[i];
		}
		else {
			mas2[i] = *item;
		}
	}



	return max;
}

