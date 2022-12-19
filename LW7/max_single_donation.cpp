#include <iostream>
#include <sstream>
#include <fstream>

using namespace std ;

using std::cin ;
using std::cout ;
using std::endl ;
using std::string ;
using std::getline ;
using std::ifstream ;
using std::istringstream ;

int main() 
{
  string fileName ;

  cout << "Enter donation filename: " << endl ;
  cin >> fileName ;
  ifstream ifs(fileName) ;
  if(!ifs.is_open())
  {
    cout << "Failed to open file "<< fileName << "." << endl;
    return 1 ;
  }

  double maxTotalDonation = 0 ;
  int maxTotalCollector = 0 ;

  string lines ;
  int line = 0 ;
  // int i, j ;

  while(getline(ifs, lines))
  {
    ++line ;
    ifs.clear() ;
    ifs.seekg(0, ifs.beg) ;
    int uin, i, j ;
    double donation, sumDonation[50] ;
    string ss ;

    for(i = 0 ; i < line && getline(ifs, ss) ; i++)
    {
      istringstream sin(ss) ;
      sumDonation[i] = 0 ;

      j = 0 ;

      while(sin >> donation)
      {
        if(j == 0)
        {
          uin = donation ;
        }
        else
        {
          sumDonation[i] = sumDonation[i] + donation ;
        }
        j =  j + 1 ;
      }
    }
    if(sumDonation[i] > maxTotalDonation && j > 2)
    {
      maxTotalDonation = sumDonation[i] ;
      maxTotalCollector = uin ;
    }
  }
  if(maxTotalDonation == 0)
  {
    cout << "No donations." << endl ;
  }
  else
  {
    cout << "Highest donation total: " << maxTotalDonation << endl;
    cout << "-- collected by id: " << maxTotalCollector << endl;
  }
  return 0 ;
}
