#include <iostream>
#include "functions.h"


using std::cout;
using std::endl ;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if(a > b)
	return false ;
	else if (a < 10)
	return false ;
	else if (b > 10000)	
	return false;
	else
	return true ;
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	
	int newDig, i, j, sameNum = 0 ;			// sameNum carries value of 'number' without going through changes/operations
	int numLength = 0 ;
	char result ;
	sameNum = number ;
	bool mountain = false ;
	bool valley = false ;
	
	while(number != 0)							// Finding number of digits
	{
		numLength = numLength + 1 ;
		number = number / 10 ;
	}

	int digList[numLength] = {} ;
	for(i = numLength-1 ; i >= 0 ; i--)				 // digits are backwards - eg: 123 -> {3, 2, 1} , for loop therefore making {1, 2, 3}
	{							
		newDig = sameNum % 10 ;
		digList[i] = newDig ;					// putting digits in array
		sameNum = sameNum / 10 ;
		if (sameNum == 0)
		break;
	}

	
	if (digList[0] < digList[1]) 
	{
		mountain = true ;
		result = 'M' ;
	} 
	else if (digList[0] > digList[1]) 
	{
		valley = true ;
		result = 'V' ;
	}
	else
	result = 'N' ;

	for(j = 1 ; j < numLength - 1 ; j++)				// refer 'program notes' file in folder
	{
		if(digList[j] < digList[j+1])
		{
			if(valley) {
				mountain = true ;
				valley = false ;
			}
			else
			return 'N' ;
		}
		else if (digList[j] > digList[j+1])
		{
			if(mountain) {
				valley = true;
				mountain = false ;
			}
			else
			return 'N' ;
		}
		else
		return 'N' ;
	
	}
	return result ;	
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt

	int mountCount = 0 ; 
	int valCount = 0;

	for(int k = a ; k <= b ; k++)
	{
		if(classify_mv_range_type(k) == 'M')
		mountCount = mountCount + 1 ;
		else if(classify_mv_range_type(k) == 'V')
		valCount = valCount + 1;
	}
	cout << "There are " << mountCount << " mountain ranges and " << valCount << " valley ranges between " << a << " and " << b << "." << endl;
}


