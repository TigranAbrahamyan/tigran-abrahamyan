#include <iostream>
#include <string>

using namespace std;

void findPermutations(string word, string result = "") {
  if (word.length() == 0) {
		cout << result << endl;
	}

	for (int i = 0; i < word.length(); i++) {
		string remainingChars = word.substr(0, i) + word.substr(i + 1);
		findPermutations(remainingChars, result + word[i]);
	}
}

int main() {
	string word;

	cout << "Word: ";
	cin >> word;

	findPermutations(word, "");

	return 0;
}
