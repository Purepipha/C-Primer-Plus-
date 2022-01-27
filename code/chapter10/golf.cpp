// golf.cpp -- member function of class Golf

#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf()
{
}

Golf::Golf(const char * name, int hc)
{
    strcpy(fullname, name);
    handicap = hc;
}
Golf::~Golf()
{
}

int Golf::setgolf()
{
    using std::cout;
    using std::cin;
    using std::endl;
    Golf temp;
    cout << "Enter the users'name: ";
    cin.getline(temp.fullname, Len);
    if(!strcmp(temp.fullname,""))
        return 0;
    cout << "Enter the users'level: ";
    while(!(cin>>temp.handicap))
    {
        cin.clear();
        while(cin.get()!='\n')
            continue;
        cout << "Bad input, please enter a integer: ";
    }
    cin.get();
    *this = temp;
    return 1;
}

void Golf::set_handicap(int hc)
{
    handicap = hc;
}

void Golf::Show() const
{
     using std::cout;
    cout << "Name: " << fullname << ", level: " << handicap << "\n" ;
}