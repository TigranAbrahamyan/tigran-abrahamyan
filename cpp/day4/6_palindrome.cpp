#include <iostream>
#include <string>

using namespace std;

bool isCharUpper(char ch) {
  return ch >= 'A' && ch <= 'Z';
}

bool isPalindrome(string word, int charDifference) {
  string reversedWord = "";

  for (int i = 0; word[i] != '\0'; i++) {
    if (isCharUpper(word[i])) {
      word[i] += charDifference;
    }

    reversedWord = word[i] + reversedWord;
  }

  return word == reversedWord;
}

int main() {
  const char charDifference = 'a' - 'A';
  string word = "";

  cout << "Write a word: ";
  cin >> word;

  if (isPalindrome(word, charDifference)) {
    cout << "Word is a palindrome";
  } else {
    cout << "Word is not a palindrome";
  }

  return 0;
}
