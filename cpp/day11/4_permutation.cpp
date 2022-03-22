#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> arr = {};

void findPermutations(string word, string result = "") {
  if (word.length() == 0) {
    bool shouldAddElemntToArray = true;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == result) {
        shouldAddElemntToArray = false;
        break;
      }
    }

    if (shouldAddElemntToArray) {
      arr.push_back(result);
    }
  } else {
    for (int i = 0; i < word.length(); i++) {
      string remainingChars = word.substr(0, i) + word.substr(i + 1);
      findPermutations(remainingChars, result + word[i]);
    }
  }
}

int main() {
  string word;

  cout << "Word: ";
  cin >> word;

  findPermutations(word, "");

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << endl;
  }

  cout << "Permutations count: " << arr.size();

  return 0;
}
