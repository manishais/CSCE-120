// TODO: Implement this header file

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include<iostream>
#include<fstream>
//#include<tuple>
#include<limits>
#include<stdexcept>
//#include "Rover.h" 
using namespace std;

class MyString
{
    private:
        size_t strSize = 0;
        size_t strCapacity = 1;
        char* line ;
    public:
        MyString();                             // constructs an empty string
        MyString (const MyString& str);          // constructs a copy of str
        MyString (const char* s) ;                // copies the null-terminated character sequence (C-string) pointed by s
        ~MyString();                            // destructor
        void resize (size_t n);
        size_t capacity() const noexcept;
        size_t size() const noexcept;
        size_t length() const noexcept;
        const char* data() const noexcept;
        bool empty() const noexcept;
        char& front() const;
        //const char& front() const;
        const char& at (size_t pos) const;
        // char& at (size_t pos);
        void clear() noexcept;
        MyString& operator= (const MyString& str);
        MyString& operator+= (const MyString& str);
        // bool operator== (const MyString& lhs, const MyString& rhs) noexcept;
        // bool operator== (const char*   lhs, const MyString& rhs);
        // bool operator== (const MyString& lhs, const char*   rhs);
        // MyString& operator= (const MyString& str);
        size_t find (const MyString& str, size_t pos = 0) const noexcept;
        
        int stoi (const MyString&  str, size_t* idx = 0, int base = 10);
        //int stoi (const MyString& str, size_t* idx = 0, int base = 10);   
};

std::ostream& operator<< (ostream& os, const MyString& str);
std::istream& operator>> (istream& is, MyString& str);

MyString operator+ (const MyString& lhs, const MyString& rhs);
MyString operator+ (MyString&& lhs, MyString&& rhs);
MyString operator+ (MyString&& lhs, const MyString& rhs);
MyString operator+ (const MyString& lhs, MyString&& rhs);  

#endif