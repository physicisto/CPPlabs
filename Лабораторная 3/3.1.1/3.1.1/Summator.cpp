#include "Summator.h"



Summator::Summator() {
}
//------------------------------------------------------------------
void Summator::print() {
	//logToScreen();
	cout << "Expression [" << nOperands << "] : " << operands[0];
	for (int i = 1; i < nOperands; i++) {
		if (operands[i] < 0) {
			cout << " + (" << operands[i] << ")";
			continue;
		}
		cout << " + " << operands[i];
	}
	cout << endl << "= " << calculate() << endl;
}
double Summator::calculate() {
	double sum = 0;
	for (int i = 0; i < nOperands; i++)
		sum += operands[i];
	return sum;
}
//------------------------------------------------------------------
Summator::~Summator(){
}
