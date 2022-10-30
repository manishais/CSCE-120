#include <iostream>
#include "cstring.h"

using std::cin ;
using std::cout ;
using std::endl ;



unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  int i = 0;
  int length = 0;
  while(str[i] != '\0')
  {
    length += 1;
    i = i + 1 ;
  }
  //cout << "found length!" << endl ;
  return length;
}

unsigned int find(char str[], char character) {
  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
  
  // int strLength, j, result;
  // j = 0;
  // strLength = length(str);
  //cout << "length is " << strLength << endl ;
  //cout << "starting loop" << endl ;
  int j = 0;

  while(str[j] != '\0'){
    if(str[j] == character)
    {
      break ;
    }
      j += 1;
  }
  // for(j = 0 ; j < strLength ; j++)
  // {
  //   //cout << "testing for " << j << endl ; 
  //   if(str[j] == character)
  //   {
  //     result = j ;
  //     //cout << "result!" ;
  //     break ;
  //   }
  //   else
  //   {
  //     result = strLength;
  //   }
  // }
  return j ;
}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
  int length1, length2, k ;
  bool result ;
  length1 = length(str1) ;
  length2 = length(str2) ;
  if(length1 == length2)
  {
    for(k = 0 ; k < length1 ; k++)
    {
      if(str1[k] != str2[k])
      {
        result = false ;
        break ;
      }
      else
      result = true ;
    }
  }
  return result ;
}
