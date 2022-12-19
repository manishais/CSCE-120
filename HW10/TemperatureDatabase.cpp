#include "TemperatureDatabase.h"

#include <fstream>
#include<string>
#include<sstream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) 
{
	// Implement this function for part 1
	std::string id;
	int year;
	int month;
	double temperature;

	ifstream streamy {filename};
	if (streamy.is_open() != true) 
	{
		cout << "Error: Unable to open input.dat" << endl;
		exit(1);
	}

	while(!streamy.eof()) 
	{
		std::string stringg = "";					// initialize with empty
		getline(streamy, stringg);					// gets stringg and puts into file object streamy

		stringstream ss(stringg);					// used because extracting numbers as strings
		ss >> id ;
		ss >> year ;
		ss >> month ;
		ss >> temperature;

		//int nowYear = 2022 ;

		if (ss.fail() && temperature != -99.99) 
		{
			cout << "Error: Other invalid input." << endl;
		}

		else if ((temperature > 50.0 || temperature < -50.0) && (temperature != -99.99))				// valid temperatures are assumed to be in the interval -50.0 to 50.0
		{
			cout << "Error: Invalid temperature " << temperature << endl;
		}

		else if (year > 2022 || year < 1800)															// The first valid year is 1800. The latest valid year should be our current year.
		{
			cout << "Error: Invalid year " << year << endl;	
		}
			
		else if (month > 12 || month < 1)																// January - December
		{
			cout << "Error: Invalid month " << month << endl;
		}
			
		else
		{
			records.insert(id, year, month, temperature);
		}		
	}

	streamy.close();
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

// void TemperatureDatabase::performQuery(const string& filename) {
// 	// Implement this function for part 2
// 	//  Leave it blank for part 1
// }
