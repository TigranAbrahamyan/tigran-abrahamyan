#include <string>

#ifndef ALPHABET_H
#define ALPHABET_H

// Check the char is upper-case or not.
bool isUpper(char);

// Check the char is lower-case or not.
bool isLower(char);

// Check the char is exists in english alphabet or not.
bool isAlpha(char);

// Transforms char to upper-case. Eg g - G.
char toUpper(char);

// Transforms char to lower-case. Eg G - g.
char toLower(char);

// Transforms string text to upper-case. Eg 'FoO bOo' - 'FOO BOO'.
std::string strToUpper(std::string);

// Transforms string text to lower-case. Eg 'FoO bOo' - 'foo boo'.
std::string strToLower(std::string);

#endif
