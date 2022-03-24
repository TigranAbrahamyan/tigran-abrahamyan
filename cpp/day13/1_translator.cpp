#include <iostream>
#include <fstream>
#include <string>

#include "../lib/alphabet/alphabet.h"

using namespace std;

bool isWordEnglish(string str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isAlpha(str[i])) {
      return false;
    }
  }

  return true;
}

bool filterFileWordSigns(char ch) {
  return ch != '-' && ch != '>' && ch != ' ';
}

int main() {
  setlocale(LC_ALL, "");

  string sentence = "";
  cout << "Input : ";
  getline(cin, sentence);

  ifstream translatorFile;
  string sentenceWord = "";
  string fileWord = "";

  cout << "Output: ";

  for (int i = 0; i <= sentence.length(); i++) {
    if (sentence[i] == ' ' || i == sentence.length() && sentenceWord != "") {
      string currentFileWord;

      if (isWordEnglish(sentenceWord)) {
        translatorFile.open("en-hy.txt");
      } else {
        translatorFile.open("hy-en.txt");
      }

      while (getline(translatorFile, fileWord)) {
        currentFileWord = "";

        for (int i = 0; i < fileWord.length(); i++) {
          if (filterFileWordSigns(fileWord[i]) && fileWord[i] == sentenceWord[i]) {
            currentFileWord += fileWord[i];
          }
        }

        if (currentFileWord == sentenceWord) {
          break;
        }
      }

      if (currentFileWord != "" && currentFileWord == sentenceWord) {
        for (int i = 0; i < fileWord.length(); i++) {
          if (filterFileWordSigns(fileWord[i]) && fileWord[i] != sentenceWord[i]) {
            cout << fileWord[i];
          }
        }

        cout << " ";
      } else {
        cout << sentenceWord << " ";
      }

      translatorFile.close();
      sentenceWord = "";
      continue;
    }

    sentenceWord += sentence[i];
  }

  cout << endl;

  return 0;
}
