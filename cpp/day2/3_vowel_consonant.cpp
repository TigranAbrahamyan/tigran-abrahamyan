#include <iostream>
using namespace std;

int main() {
	char character;
	
	cout << "Input a character: ";
	cin >> character;

	switch (character) {
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'u':
		case 'U':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
			cout << "'" << character << "' is vowel" << endl;
			break;
		default:
			cout << "'" << character << "' is consonant" << endl;
			break;
	}

	return 0;
}

