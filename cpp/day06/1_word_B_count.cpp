#include <iostream>

using namespace std;

int main() {
  string sentence = "";
  int result = 0;
  int letterBCountInWord = 0;

  cout << "Write a sentence: ";
  getline(cin, sentence);

  for (int i = 0; i < sentence.length(); i++) {
    if (sentence[i] == 'B') {
      letterBCountInWord++;
    }

    if (sentence[i] == ' ' || i == sentence.length() - 1) {
      if (letterBCountInWord == 2) {
        result++;
      }

      letterBCountInWord = 0;
    }
  }

  cout << "Words count that contains two B letter: " << result;

  return 0;
}
