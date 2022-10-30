#include <stdexcept>
#include <iostream>

using std::cout ;
using std::endl ;

int Largest(int a, int b, int c) 
{
  if(b == a && b == c && a==c)
  {
    return a ;
  }

  if(b==a) 
  {
    if(b > c)
    {
      return b ;
    }
    else
    {
      return c;
    }
  }

  if(c==a) 
  {
    if(c > b)
    {
      return c ;
    }
    else
    {
      return b;
    }
  }

  if(b==c) 
  {
    if(b > a)
    {
      return b ;
    }
      else
    {
      return a;
    }
  }
  else if(b > a && b > c)
  {
    return b ;
  }
  else if (c > a && c > b)
  {
    return c ;
  }
  else if(a > b && a > c)
  {
    return a ;
  }
  else
  return a ;

}

bool SumIsEven(int a, int b) 
{
  if((a+b) % 2 == 0)
  return true;
  else
  return false;
}

int BoxesNeeded(int apples) 
{
 // int boxes ;
  if (apples <= 0)
  return 0 ;
  if(apples <= 20 && apples > 0)
  return 1 ;

  if((apples % 20) == 0)
  return apples / 20 ;
  else
  return (apples / 20) + 1 ;
 
}

bool SmarterSection(double A_correct, double A_total, double B_correct, double B_total) 
{

  if(A_total == 0 || B_total == 0)    
  {
    throw std::invalid_argument("Invalid Arguments") ;
  }
  
 else if(A_total < A_correct || B_total < B_correct)
  {
    throw std::invalid_argument("Invalid Arguments") ;
  }

  else if(A_total < 0 || B_total < 0 || A_correct < 0 || B_correct < 0)
  {
      throw std::invalid_argument("Invalid Arguments") ;
  }

  float fracA = A_correct / A_total ;
  float fracB = B_correct / B_total ;
  

  cout << "FRAC A: " << fracA << endl ;
  cout << "FRAC B: " << fracB << endl ;

 if(((A_correct / A_total)*100) > ((B_correct / B_total)*100))
  {
    return true ;
  }

  return false ;
}

bool GoodDinner(int pizzas, bool is_weekend) 
{
  // if (pizzas >= 10 && pizzas <= 20) {
  //   if (is_weekend) 
  //   {
  //     return false;
  //   }
  //   else
  //   return true ;

  if(is_weekend)
  {
    if(pizzas >= 10)
    return true ;
    else
    return false ;
  }
  else
  {
    if(pizzas >= 10 && pizzas <= 20)
    return true ;
    else
    return false ;
  }
}

int SumBetween(int low, int high) 
{
  int sum = 0 ;

  if(low > high)
  {
    throw std::invalid_argument("Out of Order") ;
  }
  else if(low < INT32_MIN || high > INT32_MAX )
  {
    throw std::invalid_argument("Invalid") ;
  }
  int i = low ;
  while(i < high)
  {
    sum = sum + i ;
    i = i + 1 ;
  }
  sum = sum + high ;

  if (sum < INT32_MIN || sum > INT32_MAX)
  {
    throw std::overflow_error("Exceeds limits") ;
  }

  cout << "low val: " << low << endl ;
  cout <<"high val: " << high << endl ;

  // if ((low > 0) && (high > INT32_MAX - low)) 
  // throw std::overflow_error("Exceeds limits") ;

  if((INT32_MAX - low) == high || (high - INT32_MIN) == low)
  throw std::overflow_error("Exceeds limits") ;
  else
  return sum ;
}

int Product(double a, double b) 
{
  if(a <= INT32_MIN  || a >= INT32_MAX || b <= INT32_MIN  || b >= INT32_MAX)
  {
    throw std::overflow_error("Exceeds limits") ;
  }

  int product = a * b ;

  if(product >= INT32_MAX  || product <= INT32_MIN)
  {
    throw std::overflow_error("Exceeds limits") ;
  }
  
  cout << "A value: " << a << endl ;
  cout << "B value: " << b << endl ;
  cout << "Product: " << product << endl ;

  // if((INT32_MAX / a) == b || (INT32_MIN / a) == b)
  // {
  //   throw std::overflow_error("Exceeds limits") ;
  // }

  return product;
}
