#include <iostream>
#include <string>

using namespace std;

const char* TWO_INDEX_NUMBER_ERROR = "You should write only 2 index number";
const char* INDEX_NOT_FOUND = "Index not found";

bool isStrDigit(string);
void swap(string&, int, int);
void getSplittedStr(string, string*, int*);
void handleErrors(string, string*, int);

int main() {
	string num;
	string positions;
	string splittedStr[2] = {};
	int splittedStrLength = 0;

	cout << "Input number: ";
	cin >> num;

	getline(cin, positions);
	cout << "Input positions to swap: ";
	getline(cin, positions);

	getSplittedStr(positions, splittedStr, &splittedStrLength);
	handleErrors(num, splittedStr, splittedStrLength);

	int firstIndex = stoi(splittedStr[0]);
	int secondIndex = stoi(splittedStr[1]);
	swap(num, firstIndex, secondIndex);

	cout << "Result: " << num << endl;

	return 0;
}

bool isStrDigit(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}

	return true;
}

void swap(string &num, int firstIndex, int secondIndex) {
	int temp = num[firstIndex];
	num[firstIndex] = num[secondIndex];
	num[secondIndex] = temp;
}

void getSplittedStr(string positions, string *splittedStr, int *splittedStrLength) {
	for (int i = 0; positions[i] != '\0'; i++) {
		if (*splittedStrLength > 1) {
			break;
		}

		if (positions[i] == ' ') {
			*splittedStrLength += 1;
			continue;
		}

		splittedStr[*splittedStrLength] += positions[i];
	}
}

void handleErrors(string num, string *splittedStr, int splittedStrLength) {
	try {
		if (splittedStrLength != 1) {
			throw TWO_INDEX_NUMBER_ERROR;
		}

		if (!isStrDigit(splittedStr[0]) || !isStrDigit(splittedStr[1])) {
			throw TWO_INDEX_NUMBER_ERROR;
		}

		if (stoi(splittedStr[0]) >= num.length() || stoi(splittedStr[1]) >= num.length()) {
			throw INDEX_NOT_FOUND;
		}
	} catch (const char* err) {
		cout << "================================" << endl;
		cout << "Error: " << err << endl;
		exit(0);
	}
}
