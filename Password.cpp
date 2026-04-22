#include "Password.h"
#include <string>
#include <cctype>

using std::string;

int Password::count_leading_characters(string phrase){
  if (phrase.length() == 0) return 0;

  int repetition = 1;
  int index = 0;

  while(index < (int)phrase.length() - 1 &&
        phrase[index] == phrase[index + 1]) {
    repetition++;
    index++;
  }

  return repetition;
}

bool Password::has_mixed_case(string pass){
  bool hasUpper = false;
  bool hasLower = false;

  for (char c : pass){
    if (std::isupper((unsigned char)c)) hasUpper = true;
    if (std::islower((unsigned char)c)) hasLower = true;
  }

  return hasUpper && hasLower;
}

unsigned int unique_characters(string str){
  bool seen[256] = {false};
  unsigned int count = 0;

  for (char c : str){
    unsigned char uc = (unsigned char)c;
    if (!seen[uc]){
      seen[uc] = true;
      count++;
    }
  }

  return count;
}