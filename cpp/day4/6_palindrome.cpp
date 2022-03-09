#include <iostream>
#include <string>

using namespace std;

bool isCharUpper(char ch) {
  return ch >= 'A' && ch <= 'Z';
}

void checkPalindrome(string word) {
  string reversedWord = "";
  char charDifference = 'a' - 'A';

  for (int i = 0; word[i] != '\0'; i++) {
    if (isCharUpper(word[i])) {
      word[i] = word[i] + charDifference;
    }

    reversedWord = word[i] + reversedWord;
  }

  if (word == reversedWord) {
    cout << "Word is a palindrome";
  } else {
    cout << "Word is not a palindrome";
  }
}

int main() {
  string word = "";
  cout << "Write a word: ";
  cin >> word;

  checkPalindrome(word);
  cout << endl;

  return 0;
}
