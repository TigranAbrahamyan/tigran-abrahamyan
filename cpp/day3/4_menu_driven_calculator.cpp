#include <iostream>

using namespace std;

void calcResult(double firstNumber, double secondNumber, char arithmeticOperator) {
	double result = 0;

	switch (arithmeticOperator) {
		case '+':
			result = firstNumber + secondNumber;
			break;
		case '-':
			result = firstNumber - secondNumber;
			break;
		case '*':
			result = firstNumber * secondNumber;
			break;
		case '/':
			if (secondNumber == 0) {
				cout << "You cannot divide to 0" << endl;
				return;
			} else {
				result = firstNumber / secondNumber;
				break;
			}
		default:
			cout << "Operator not found" << endl;
			return;
	}

	cout << firstNumber << " " << arithmeticOperator << " " << secondNumber << " = " << result << endl;
}

int main() {
	double firstNumber = 0;
	double secondNumber = 0;
	char arithmeticOperator;

	cout << "Input a first number: ";
	cin >> firstNumber;
  cin.ignore(1000, '\n');

	cout << "Input a operator: ";
	cin >> arithmeticOperator;
  cin.ignore(1000, '\n');

	cout << "Input a second number: ";
	cin >> secondNumber;

	calcResult(firstNumber, secondNumber, arithmeticOperator);

	return 0;
}
