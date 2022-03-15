#include <iostream>
#include <string>

using namespace std;

int myatoi(string str) {
  int result = 0;
  char *start = str[0] == '-' ? &str[1] : &str[0];
  char *end = &str[0] + str.length() - 1;

  while (start <= end) {
    if (*start >= '0' && *start <= '9') {
      result = (result * 10) + (*start - '0');
      start++;
    } else {
      break;
    }
  }

  return str[0] == '-' ? -result : result;
}
