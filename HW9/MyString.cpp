//TODO: Implement this source file
#include<iostream>
// #include<fstream>
// #include<tuple>
// #include<limits>
// #include<stdexcept>
#include "MyString.h"
// #include "Rover.h" 
//using namespace std;

MyString::MyString() : strSize(0), strCapacity(1), line(nullptr)                                    // constructor that creates the empty string 
{
    line = new char [strCapacity];
    line[0] = '\0' ;
}

MyString::MyString(const MyString& s) : strSize(0), strCapacity(1), line(nullptr)               // copy constructor
{
    // if(s.at(0)== '\0')
    // {
    //     strCapacity = 1 ;
    //     strSize = 0 ;
    //     char* copy = new char [strCapacity];
    // }
    // if(s.size() != 0)
    // {
        strSize = s.size() ;
        strCapacity = s.capacity() ;
        line = new char [strCapacity];

        for(size_t i = 0 ; i < strSize ; i++)
        {
            line[i] = s.line[i] ;
        }
     line [strSize] ='\0';
    }
   
    // else
    // {
    //     strCapacity = 1 ;
    //     strSize = 0 ;
    //     line = new char [strCapacity] {'\0'};
    // }


MyString::MyString(const char* s) : strSize(0), strCapacity(1), line(nullptr)
{
    size_t i = 0 ;

    while(s[i] != '\0')
    {

        i++;
    }
    strSize = i ;
    strCapacity = strSize + 1;

    line = new char [strCapacity];

    // for(size_t i = 0 ; s[i] != '\0' ; i++)
    // {
    //     line[i] = s[i] ;
    // }

     for(size_t j = 0 ; j < i ; j++)
     {
        line[j] = s[j] ;
     }
     line[strSize] = '\0';
}

MyString::~MyString()
{
    delete[] line;
}

size_t MyString::capacity() const noexcept
{
    return strCapacity;
}
size_t MyString::size() const noexcept
{
    return strSize;
}
size_t MyString::length() const noexcept
{
    return strSize;
}
// void resize (size_t capacity)
// {

// }

bool MyString::empty() const noexcept
{
    if(strSize == 0 || line == nullptr || line[0] == '\0')
        return true;
    else
        return false;
}


MyString& MyString::operator+=(const MyString& string2)
{
    size_t size1 = strSize;
    size_t size2 = string2.size();
    size_t totalSize = size1 + size2 ;


    size_t totalCap = totalSize +1;          // getting rid of an extra null char

    char* newArray = new char [totalCap];

    for(size_t i = 0 ; i < size1 ; i++)
    {
        newArray[i] = line[i] ;
    }
    for(size_t j = 0 ; j < size2 ; j++)
    {
        newArray[size1 + j] = string2.data()[j] ;
    }
        
    delete[] line ;
    line = newArray ;
    strSize = totalSize ;
    strCapacity = totalCap ;
    line[strSize] = '\0';
    return *this ;
}

const char& MyString::at (size_t pos) const
{
    // if(pos <= strSize && pos >= 0)
    // {
    //     return this->line[pos];
    // }
    // else
    // {
    //     throw std::out_of_range("greater than size");
    // }

    if(pos >= strSize)
    {
        throw std::out_of_range("too big") ;
    }
    // if(pos < 0)
    // {
    //     throw std:: out_of_range("too small");
    // }
    return this->line[pos];
    
}
void MyString::clear() noexcept
{
    delete[] line;
    strSize = 0 ;
    line = nullptr;
    //strCapacity = 1 ;
    strCapacity = 1;
    line = new char [1];
    line[0] = '\0';
}

const char* MyString::data() const noexcept
{
    return line;
}

void MyString::resize (size_t n)
{
    // char* newArray = new char [strCapacity];

    // if(n < strSize)
    // {
    //     strSize= n ;
    //     // MyString(const MyString& line);         // copying first n elements
    //     for(size_t i = 0 ; i < n ; i++)
    //     {
    //         newArray[i] = line[i] ;
    //     }
    // }
    // if(n > strSize)
    // {
    //     strSize =  n ;
    //     for(size_t i = 0 ; i < strSize ; i++)
    //     {
    //         newArray[i] = line[i] ;
    //     }
    // }
    // // delete[] line;
    // line = newArray ;
}

std::ostream& operator << (ostream& os, const MyString& str)
{
    for(size_t i = 0 ; i < str.size() ; i++)
    {
        os << str.data()[i] ;
    }
    return os;
}

MyString& MyString::operator= (const MyString& str)
{
    delete[] line ;
    line = new char[str.capacity()];

    for(size_t i = 0 ; i < str.size() ; i++)
    {
        line[i] = str.data()[i] ;
    }

    strSize = str.strSize ;
    strCapacity = str.strCapacity ;

    line[strSize] = '\0' ;

    return *this ;
}

// std::istream& operator>> (istream& is, MyString& str)
// {
//     for(int i = 0 ; i < str.size() ; i++)
//     {
//         is << str.at(i) ;
//     }
//     return is;   
// }

size_t MyString::find (const MyString& str, size_t pos) const noexcept
{
    for(size_t i = pos ; i < this->size() ; i++)
    {
        if(str.line[0] == line[i])                                    // checking if first characters match
        { 
            for(size_t j = 0  ; j < str.size() ; j++)
            {
                if(i+j >= this->size()){
                    break;
                }
                else if(line[i+j] != str.line[j])
                {
                    break ;
                   // count = count + 1 ;
                }
                else if(j == str.size() -1 && line[i+j] == str.line[j])
                {
                    return i ;
                }
            }
            // if(count == str.size())
            // {
            //     return i ;
            // }
        }
    }
    return -1 ;
}
    

 char& MyString::front() const
 {
    // if(strSize == 0 || line == nullptr)
    // {
    //     throw out_of_range("size is zero") ;
    // }

    return line[0];
 }

// int main(){

//     MyString c1("Hello");
//     //MyString c2("Howdy");
//     //c1 += c2;
//     std::cout << c1;
//     return 0;
// }
