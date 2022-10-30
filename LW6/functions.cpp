#include "functions.h"
#include <iostream>
#include <string>
#include <sstream>
using std::cin ;
using std::cout ;
using std::endl ;
using std::ostream ;
using std::string ;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack& stack, int number) 
{
  // TODO: implement push function for stack
  INFO_STRUCT(stack);
  INFO(number);

  if(stack.count > stack.capacity)
  {
    for(int i = 0 ; i < stack.count ; i++)
    {
      stack.newNumbers[i] = stack.numbers[i] ;
    }
    delete stack.numbers ;
    stack.newNumbers[stack.count] = number ;
    stack.count = stack.count + 1 ;
  }
  else
  {
    stack.numbers[stack.count] = number ;
    stack.count = stack.count + 1 ;
  }
  
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  // TODO: implement pop function for stack
  int popped ;
  if(stack.count == 0)
  {
    return INT32_MAX ;
  }
  else
  {
    popped = stack.numbers[stack.count - 1] ;
    stack.count = stack.count - 1 ;
    return popped ; 
  }

  INFO_STRUCT(stack);
  return 0 ;

}

/**
 * ----- OPTIONAL -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  // TODO (optional): implement peek function for stack

int i, newCount ;

if(stack.count == 0)
{
  return INT32_MAX ;
}
int* temp = new int[stack.capacity] ;
int total = 0 ;

for(i = 0 ; i < stack.count - 2 ; i++)
{
  temp[i] = stack.numbers[i] ;
  total = total + temp[i] ;
}
newCount = stack.count - 1 ;
  return newCount ;
}
