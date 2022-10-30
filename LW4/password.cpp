#include <iostream>
#include <string>
using std::cin ;
using std::cout ;
using std::endl ;
using std::string ;

int main() 
{
    string password, newPassword, temp , tempBackward ;
    int i, length, j, k ;

    cout << "Please enter your text input: " ;
    cin >> password ;
    cout << "input: " << password << endl ;

    length = password.length() ;
    temp = password ;

    for(i = 0 ; i < length ; i++)
    {
        if(password[i] == 'a')
        password[i] = '@' ;
        else if(password[i] == 'e')
        password[i] = '3' ;
        else if(password[i] == 'i')
        password[i] = '!' ;
        else if(password[i] == 'o')
        password[i] = '0' ;
        else if(password[i] == 'u')
        password[i] = '^' ;
    }

    //tempLength = password.length();
    temp = password ;

    for(j = length - 1; j >= 0 ; j--)
    {
        if(temp[j] == 'a')
        temp[j] = '@';
        else if(temp[j] == 'e')
        temp[j] = '3' ;
        else if(temp[j] == 'i') 
        temp[j] = '!' ; 
        else if(temp[j] == 'o') 
        temp[j] = '0' ; 
        else if(temp[j] == 'u') 
        temp[j] = '^' ;
    }

    for(k = length - 1; k >= 0 ; k--)
    {
        tempBackward = tempBackward + temp[k] ;
    }

    newPassword = password + tempBackward ;
    cout << "output: " << newPassword << endl ;
}
