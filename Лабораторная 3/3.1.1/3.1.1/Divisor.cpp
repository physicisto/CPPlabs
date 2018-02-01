#include "Divisor.h"



Divisor::Divisor(){
}
//------------------------------------------------------------------
void Divisor::print() {
	cout << "Expression [" << nOperands << "] : " << operands[0];
	for (int i = 1; i < nOperands; i++) {
		if (operands[i] < 0) {
			cout << " / (" << operands[i] << ")";
			continue;
		}
		cout << " / " << operands[i];
	}
	cout << endl << "= " << calculate() << endl;
}
double Divisor::calculate() {
	for (int i = 0; i < nOperands; i++) {
		if (operands[i] == 0)
			return 0;
	}
	double div = operands[0];
	for (int i = 1; i < nOperands; i++)
		div /= operands[i];
	return div; 
}
//------------------------------------------------------------------
//Реализация интерфейса IShuffle:
//Переставить операнды так, чтобы сначала шли все отрицательные, а затем положительные
void Divisor::shuffle() {
	double* temp = new double[nOperands];
	int count = 0;
	for (int i = 0; i < nOperands; i++) {
		if (operands[i] < 0) {
			temp[count] = operands[i];
			count++;
		}
	}
	for (int i = 0; i < nOperands; i++) {
		if (operands[i] >= 0) {
			temp[count] = operands[i];
			count++;
		}
	}
	for (int i = 0; i < nOperands; i++)		//копируем временный массив в operands
		operands[i] = temp[i];
	delete[]temp;
}
//Если i-ый операнд отрицателен, а j-ый – нет, то поменять их местами
void Divisor::shuffle(int i, int j) {
	if (operands[i-1] < 0 && operands[j-1] >= 0) {
		double temp = operands[i-1];
		operands[i-1] = operands[j-1];
		operands[j-1] = temp;
	}
}
//------------------------------------------------------------------
Divisor::~Divisor(){
}
