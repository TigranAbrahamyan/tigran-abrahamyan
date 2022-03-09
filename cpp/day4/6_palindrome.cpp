#include <iostream>
#include <string>

using namespace std;

bool isCharUpper(char ch) {
  return ch >= 'A' && ch <= 'Z';
}

string checkPalindrome(string word) {
  string reversedWord = "";
  char charDifference = 'a' - 'A';

  for (int i = 0; word[i] != '\0'; i++) {
    if (isCharUpper(word[i])) {
      word[i] = word[i] + charDifference;
    }

    reversedWord = word[i] + reversedWord;
  }


  return word == reversedWord ? "Word is a palindrome" : "Word is not a palindrome";
}

int main() {
  string word = "";
  cout << "Write a word: ";
  cin >> word;

  cout << checkPalindrome(word) << endl;

  return 0;
}
