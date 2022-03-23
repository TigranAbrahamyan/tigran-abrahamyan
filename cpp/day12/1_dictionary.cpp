#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> WORDS = {};

ifstream DICTIONARY_FILE;
string DICTIONARY_FILENAME = "dictionary.txt";

ofstream CORRECTED_SENTENCE_FILE;
string CORRECTED_SENTENCE_FILENAME = "corrected.txt";

void fillWordsArray(string);
void readCorrectedSentenceFile();
void wordsHandling();

int main() {
  string sentence = "";
  cout << "Input: ";
  getline(cin, sentence);

  fillWordsArray(sentence);
  wordsHandling();
  readCorrectedSentenceFile();

  return 0;
}

void fillWordsArray(string sentence) {
  string word = "";

  for (int i = 0; i <= sentence.length(); i++) {
    if (sentence[i] == ' ' || i == sentence.length()) {
      WORDS.push_back(word);
      word = "";
      continue;
    }

    word += sentence[i];
  }
}

void readCorrectedSentenceFile() {
  CORRECTED_SENTENCE_FILE.open(CORRECTED_SENTENCE_FILENAME);

  for (int i = 0; i < WORDS.size(); i++) {
    CORRECTED_SENTENCE_FILE << WORDS[i] << (i != WORDS.size() - 1 ? " " : "");
  }

  CORRECTED_SENTENCE_FILE.close();
}

void wordsHandling() {
  string fileWord = "";

  for (int i = 0; i < WORDS.size(); i++) {
    DICTIONARY_FILE.open(DICTIONARY_FILENAME);
    bool isWordCorrect = true;

    try {
      if (!DICTIONARY_FILE.good()) {
        throw ("File '" + DICTIONARY_FILENAME + "' not found");
      }

      while (getline(DICTIONARY_FILE, fileWord)) {
        if (WORDS[i] == fileWord) {
          isWordCorrect = true;
          break;
        } else {
          isWordCorrect = false;
        }
      }

      DICTIONARY_FILE.close();
    } catch (const string &err) {
      DICTIONARY_FILE.close();
      cout << err << endl;
      exit(0);
    }

    if (!isWordCorrect) {
      DICTIONARY_FILE.open(DICTIONARY_FILENAME);

      try {
        if (!DICTIONARY_FILE.good()) {
          throw ("File '" + DICTIONARY_FILENAME + "' not found");
        }

        while (getline(DICTIONARY_FILE, fileWord)) {
          if (WORDS[i].length() == fileWord.length()) {
            int incorrectLetters = 0;

            for (int j = 0; j < fileWord.length(); j++) {
              if (incorrectLetters >= 2) {
                break;
              }

              if (fileWord[j] != WORDS[i][j]) {
                incorrectLetters += 1;
              }
            }

            if (incorrectLetters == 1) {
              WORDS[i] = fileWord;
              break;
            }
          }
        }

        DICTIONARY_FILE.close();
      } catch (const string &err) {
        DICTIONARY_FILE.close();
        cout << err << endl;
        exit(0);
      }
    }
  }
}
