// person.cpp -- Person member function
#include <iostream>
#include <cstring>
#include "person.h"

Person::Person(const std::string & ln, const char * fn)
{
    lname = ln;
    strcpy(fname, fn);
}

void Person::Show() const
{
    using std::cout;
    cout << fname << " " << lname;
}

void Person::FormalShow() const
{
    std::cout << lname << ", " << fname << "\n";
}