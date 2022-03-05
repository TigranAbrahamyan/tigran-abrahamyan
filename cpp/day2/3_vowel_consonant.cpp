#include <iostream>
using namespace std;

int main() {
	string character = "";
	int characterIndex = 0;

	cout << "Input a character: ";
	cin >> character;

	if (character == "a") {
		characterIndex = 1;
	} else if (character == "e") {
		characterIndex = 2;
	} else if (character == "u") {
		characterIndex = 3;
	} else if (character == "i") {
		characterIndex = 4;
	} else if (character == "o") {
		characterIndex = 5;
	}

	switch (characterIndex) {
		case 1:
			cout << "'" << character << "' is vowel" << endl;
			break;
		case 2:
			cout << "'" << character << "' is vowel" << endl;
			break;
		case 3:
			cout << "'" << character << "' is vowel" << endl;
			break;
		case 4:
			cout << "'" << character << "' is vowel" << endl;
			break;
		case 5:
			cout << "'" << character << "' is vowel" << endl;
			break;
		default:
			cout << "'" << character << "' is consonant" << endl;
			break;
	}

	return 0;
}

