#include <iostream>
#include "Summator.h"
#include "Divisor.h"
#include "CustomExpressionEvaluator.h"
#include "IShuffle.h"
using namespace std;

void main() {
	//объ€вл€ем массив указателей
	ExpressionEvaluator* evaluators[3];
	evaluators[0] = new Summator;
	evaluators[1] = new Divisor;
	evaluators[2] = new CustomExpressionEvaluator;

	//заполн€ем установленными способами
	//Summator: 7 операндов, присвоить группой 5, 12.5, 9, Ц1.5, -9.5, 0, 11
	double s[7]{ 5, 12.5, 9, -1.5, -9.5, 0, 11 };
	evaluators[0]->setOperands(s, 7);
	//Divisor: 4 операнда, присвоить поэлементно 100, -4, 2.5, -4
	evaluators[1]->setOperand(1, 100);
	evaluators[1]->setOperand(4, -4);
	evaluators[1]->setOperand(3, 2.5);
	evaluators[1]->setOperand(2, -4);
	//CustomExpressionEvaluator: 5 операндов, присвоить группой 5, 4, -2, 9, 3
	double c[5]{ 5, 4, -2, 9, 3 };
	evaluators[2]->setOperands(c, 5);

	//проход в цикле по указател€м evaluators и вывод на консоль и в файл лога выражени€
	//демонстраци€ полиморфизма
	for (int i = 0; i < 3; i++) {
		evaluators[i]->logToFile("log.txt");
		evaluators[i]->print();   //print() вызывает logToScreen() и выводит результат на консоль
	}

	//проверка типа текущего объекта на реализацию интерфейса IShuffle
	for (int i = 0; i < 3; i++) {
		IShuffle* is = dynamic_cast<IShuffle*>(evaluators[i]);
		if (is) {
			is->shuffle();
			evaluators[i]->print();
		}
	}

	//освобождение пам€ти
	for (int i = 0; i < 3; i++)
		delete evaluators[i];
	system("pause");
}