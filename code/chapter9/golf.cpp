// golf.cpp -- defination of dealing with golf function 
#include<iostream>
#include<cstring>
#include"golf.h"

void setgolf(golf & g, const char * name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g)
{
    using std::cout;
    using std::cin;
    using std::endl;
    char name[Len];
    int hc;
    cout << "Enter the users'name: ";
    cin.getline(name, Len);
    if(!strcmp(name,""))
        return 0;
    strcpy(g.fullname,name);
    cout << "Enter the users'level: ";
    while(!(cin>>hc))
    {
        cin.clear();
        while(cin.get()!='\n')
            continue;
        cout << "Bad input, please enter a integer: ";
    }
    g.handicap = hc;
    cin.get();
    return 1;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    using std::cout;
    cout << "Name: " << g.fullname << ", level: " << g.handicap << "\n" ;
}