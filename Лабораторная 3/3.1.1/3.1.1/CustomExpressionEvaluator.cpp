#include "CustomExpressionEvaluator.h"



CustomExpressionEvaluator::CustomExpressionEvaluator()
{
}

void CustomExpressionEvaluator::print() {
	cout << "Expression [" << nOperands << "] : " << operands[0];
	for (int i = 1; i < nOperands; i++) {
		if (i % 2) {
			if (operands[i] < 0) {
				cout << " - (" << operands[i] << ")";
				continue;
			}
			cout << " - " << operands[i];
		}
		else {
			if (operands[i] < 0) {
				cout << " + (" << operands[i] << ")";
				continue;
			}
			cout << " + " << operands[i];
		}
	}
	cout << endl << "= " << calculate() << endl;
}
double CustomExpressionEvaluator::calculate() { 
	double custom = operands[0];
	for (int i = 1; i < nOperands; i++) {
		if (i % 2) {
			custom -= operands[i];
		}
		else
			custom += operands[i];
	}
	return custom; 
}
//------------------------------------------------------------------
//Переставить операнды так, чтобы сначала шли все отрицательные, а затем положительные
void CustomExpressionEvaluator::shuffle() {
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
void CustomExpressionEvaluator::shuffle(int i, int j) {
	if (operands[i-1] < 0 && operands[j-1] >= 0) {
		double temp = operands[i-1];
		operands[i-1] = operands[j-1];
		operands[j-1] = temp;
	}
}
//------------------------------------------------------------------
CustomExpressionEvaluator::~CustomExpressionEvaluator()
{
}
