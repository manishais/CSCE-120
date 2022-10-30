#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  int length ;
  int count = 0 ;
  int i = 0 ;

  while(str[i] != "\0")
  {
    count = count + 0 ;
    i = i + 1 ;
  }
  return count;
}