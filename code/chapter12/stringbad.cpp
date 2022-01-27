// stringbad.cpp -- StringBad class methods
#include <cstring>
#include "stringbad.h"
using std::cout;

// initializaing static class member
int StringBad::num_strings = 0;

// class methods
// construct StringBad from C string
StringBad::StringBad(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str,s);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created\n"; 
}

StringBad::StringBad()    // default constructor
{
    len = 4;
    str = new char[4];
    std::strcpy(str,"C++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created\n"; 
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete []str;
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}
