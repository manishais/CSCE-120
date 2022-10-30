#include <iostream>
#include <string>
using std::cin ;
using std::cout ;
using std::endl ;
using std::string ;

bool palindrome(string word)
{
    int i = 0;
    int j = word.size() - 1 ;

    while(i < j)
    {
        if(word[i] != word[j])
        {
            return false ;
        }
        i = i + 1 ;
        j = j - 1 ;
    }

    return true ;
}

int main() 
{
    int count = 0 ;
    string word ; 
    cout << "Please enter a sentence (end with 'quit'): " ;
    while(cin >> word)
    {
        if(word == "quit")
        break ;
        if(palindrome(word))
        count =  count + 1 ;
    }

    if(count == 0)
    {
        cout << "You have typed 0 palindrome." << endl ;
    }
    else if (count == 1)
    {
        cout << "You have typed 1 palindrome." << endl ;
    }
    else
    {
        cout << "You have typed " << count << " palindromes." << endl ;
    }

    return 0;
}