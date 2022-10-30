#include <iostream>
#include <iomanip>
#include <string>
#include "parallel_tracks.h"


using std::string;
using std::cin;
using std::cout;
using std::endl;

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data( double timeArray[], std::string countryArray[], unsigned int numberArray[], std::string lastnameArray[]) 
{
  //TODO
  // Update function to return the correct boolean values based on the parameters

	int i, j, length, c,k ;

	for(i = 0 ; i < 9 ; i++)
	{
		cin >> timeArray[i] ;
		cin >> countryArray[i] ;
		cin >> numberArray[i] ;
		cin >> lastnameArray[i] ;
	}
	for(k = 0 ; k < 9 ; k++)
	{
		if (timeArray[k] < 0)						// validating time
		return false ;

		if(countryArray[k].length() != 3)
		return false ;
		else
		{
			for(c = 0 ; c < 3 ; c++)
			{
				if (isupper(countryArray[k][c]) == true)		// checking if all uppercase
				return false ;
			}						
		}
		
		if (numberArray[k] > 99)			// checking one or two digits for number
		return false ;

		trim(lastnameArray[k]) ;							// validating last name
		length = lastnameArray[k].length() ;
		if(length < 1)
		return false ;
		else
		{
			for(j = 0 ; j < length ; j++)
			{
				if(isalpha(lastnameArray[k][j])== false)
				return false ;
			}
		}
	}
	return true ;				// returning all validated results
}


//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  int k ;

  for(k = 0 ; k < 9; k++)
  ary[k] = 0 ;
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	int l ;

	for(l = 0 ; l < 9 ; l++)
	ary[l] = 0 ;
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
	int m ;

	for(m = 0 ; m < 9 ; m++)
	ary[m] = "N/A" ;
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	//int ranking = 0;
	//unsigned int n , o ;
	
	// Making new array called rank with rank numbers NOT in sorted order eg: [9 , 2 , 5 , 1 , 3 , 8 , 6 , 4 , 7]
	
	for(unsigned int n = 0 ; n <= 9 ; n++)
	{
		int ranking = 1 ;
		for(unsigned int o = 0 ; o < 9 ; o++)
		{
			if(timeArray[o] < timeArray[n] && o != n)
			ranking = ranking + 1;
		}
		rankArray[n] = ranking ;
	}
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}

std::string trim(std::string ret) {
	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
			ret.erase(0, 1);
		}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size()-1))) {
		ret.erase(ret.size()-1, 1);
	}
	
	return ret;
}