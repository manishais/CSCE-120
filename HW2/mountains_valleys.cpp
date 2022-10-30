#include <iostream>
#include "functions.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	// TODO(student): print prompt for input
	cout << "Enter numbers 10 <= a <= b < 10000: ";

	// TODO(student): read the numbers from standard input
	int num1 = 0;
	int num2 = 0;
	cin >> num1; 			// enter first number of range into 'num1'			
	cin >> num2; 			// enter last number of range into 'num2'

	// TODO(student): validate input (and reprompt on invalid input)
	while(is_valid_range(num1 , num2) == false) 
	{
		cout << "Invalid Input" << endl ;
		cout << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> num1 ;
		cin >> num2 ;
	}

	// TODO(student): compute and display solution
	count_valid_mv_numbers(num1 , num2);
	
	return 0;
}
