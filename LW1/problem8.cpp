#include <iostream>

bool f(bool x, bool y, bool z) 
{
  bool f = true ;
  f = (x && !y && !z) || (y && z) || (!x && z) || (!x && y); // TODO: change this line
  return f ;
}
