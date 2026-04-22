#ifndef PRACTICE_H
#define PRACTICE_H

#include <string>

using std::string;

class Password
{
public:
  int count_leading_characters(string word);
  bool has_mixed_case(string);
};

unsigned int unique_characters(string str);

#endif