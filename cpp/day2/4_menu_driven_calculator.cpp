#include <iostream>
using namespace std;

int main() {
	double firstNumber = 0;
	double secondNumber = 0;
	double result = 0;
	char arithmeticOperator;
	
	cout << "Input a first number: ";
	cin >> firstNumber;
	cout << "Input a operator: ";
	cin >> arithmeticOperator;
	cout << "Input a second number: ";
	cin >> secondNumber;

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
			result = firstNumber / secondNumber;
			break;
		default:
			cout << "Operator not found" << endl;
			return 0;
	}

	cout << firstNumber << " " << arithmeticOperator << " " << secondNumber << " = " << result << endl;

	return 0;
}

