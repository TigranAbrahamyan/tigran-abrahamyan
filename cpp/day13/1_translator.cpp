#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

#include "../lib/alphabet/alphabet.h"

using namespace std;

bool isWordEnglish(string);
bool filterFileWordSigns(char);
void translatedSentenceResult(string);
string findAndGetFileLine(ifstream&, string&, string);
string translatedWord(string, string);

int main() {
  setlocale(LC_ALL, "");

  string sentence = "";
  cout << "Input: ";
  getline(cin, sentence);

  ifstream translatorFile;

  string translatedSentence = "";
  string sentenceWord = "";
  string fileWord = "";

  for (int i = 0; i <= sentence.length(); i++) {
    if (sentence[i] == ' ' || i == sentence.length() && sentenceWord != "") {
      if (isWordEnglish(sentenceWord)) {
        translatorFile.open("en-hy.txt");
      } else {
        translatorFile.open("hy-en.txt");
      }

      string currentFileWord = findAndGetFileLine(translatorFile, fileWord, sentenceWord);

      if (currentFileWord != "" && currentFileWord == sentenceWord) {
        translatedSentence += translatedWord(fileWord, sentenceWord) + " ";
      } else {
        translatedSentence += sentenceWord + " ";
      }

      translatorFile.close();
      sentenceWord = "";
      continue;
    }

    sentenceWord += sentence[i];
  }

  translatedSentenceResult(translatedSentence);

  return 0;
}

bool isWordEnglish(string str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isAlpha(str[i])) {
      return false;
    }
  }

  return true;
}

bool filterFileWordSigns(char ch) {
  return ch != '-' && ch != '>' && ch != ' ' && ch != '\r';
}

void translatedSentenceResult(string translatedSentence) {
  ofstream translationResultFile("translation-result.txt");
  translationResultFile << translatedSentence;
  translationResultFile.close();
}

string findAndGetFileLine(ifstream &translatorFile, string &fileWord, string sentenceWord) {
  string result = "";

  while (getline(translatorFile, fileWord)) {
    result = "";

    for (int i = 0; i < fileWord.length(); i++) {
      if (filterFileWordSigns(fileWord[i]) && fileWord[i] == sentenceWord[i]) {
        result += fileWord[i];
      }
    }

    if (result == sentenceWord) {
      break;
    }
  }

  return result;
}

string translatedWord(string fileWord, string sentenceWord) {
  string result = "";

  for (int i = 0; i < fileWord.length(); i++) {
    if (filterFileWordSigns(fileWord[i]) && fileWord[i] != sentenceWord[i]) {
      result += fileWord[i];
    }
  }

  return result;
}
