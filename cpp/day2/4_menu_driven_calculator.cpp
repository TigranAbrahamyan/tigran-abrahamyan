#include <iostream>
using namespace std;

int main() {
	int firstNumber = 0;
	int secondNumber = 0;
	string arithmeticOperator;
	int operatorIndex = 0;
	int result = 0;

	cout << "Input a first number: ";
	cin >> firstNumber;
	cout << "Input a operator: ";
	cin >> arithmeticOperator;
	cout << "Input a second number: ";
	cin >> secondNumber;

	if (arithmeticOperator == "+") {
		operatorIndex = 1;
	} else if (arithmeticOperator == "-") {
		operatorIndex = 2;
	} else if (arithmeticOperator == "*") {
		operatorIndex = 3;
	} else if (arithmeticOperator == "/") {
		operatorIndex = 4;
	}

	switch (operatorIndex) {
		case 1:
			result = firstNumber + secondNumber;
			cout << firstNumber << " + " << secondNumber << " = " << result << endl;
			break;
		case 2:
			result = firstNumber - secondNumber;
			cout << firstNumber << " - " << secondNumber << " = " << result << endl;
			break;
		case 3:
			result = firstNumber * secondNumber;
			cout << firstNumber << " * " << secondNumber << " = " << result << endl;
			break;
		case 4:
			result = firstNumber / secondNumber;
			cout << firstNumber << " / " << secondNumber << " = " << result << endl;
			break;
		default:
			cout << "Operator not found" << endl;
			break;
	}
}

