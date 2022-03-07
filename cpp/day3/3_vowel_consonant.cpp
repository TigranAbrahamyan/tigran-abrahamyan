#include <iostream>

using namespace std;

bool isCharLower(char ch) {
  return ch >= 'a' && ch <= 'z';
}

bool isCharUpper(char ch) {
  return ch >= 'A' && ch <= 'Z';
}

bool isAlpha(char ch) {
	return isCharLower(ch) || isCharUpper(ch);
}

char myCharacter() {
	char ch;

  cout << "Input a character: ";
  cin >> ch;

  while (true) {
    if (isAlpha(ch)) {
      break;
    }

		cout << "Invalid character, input again: ";
    cin.ignore(1000, '\n');
		cin >> ch;
  }

	return ch;
}

int main() {
  char ch = myCharacter();

	switch (ch) {
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
			cout << "'" << ch << "' is vowel" << endl;
			break;
		default:
			cout << "'" << ch << "' is consonant" << endl;
			break;
	}

	return 0;
}
