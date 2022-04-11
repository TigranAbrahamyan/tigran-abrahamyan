#include <string>
#include "alphabet.h"

bool isUpper(char ch) {
  return ch >= 'A' && ch <= 'Z';
}

bool isLower(char ch) {
  return ch >= 'a' && ch <= 'z';
}

bool isAlpha(char ch) {
  return isUpper(ch) || isLower(ch);
}

char toUpper(char ch) {
  if (isLower(ch)) {
    return ch - ('a' - 'A');
  }

  return ch;
}

char toLower(char ch) {
  if (isUpper(ch)) {
    return ch + ('a' - 'A');
  }

  return ch;
}

std::string strToUpper(std::string str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = toUpper(str[i]);
  }

  return str;
}

std::string strToLower(std::string str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = toLower(str[i]);
  }

  return str;
}
