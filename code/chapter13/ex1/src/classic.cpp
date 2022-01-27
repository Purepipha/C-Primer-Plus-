// classic.cpp -- methods for Classic class
#include <iostream>
#include <cstring>
#include "classic.h"

// methods of Cd
Cd::Cd(char * s1, char * s2, int n, double x)
{
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd()
{
}

void Cd::Report() const
{
    using std::cout;
    using std::endl;
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}

// methods of Classic
Classic::Classic(char * fn, char * pf, char * lb, 
        int sel, double pt) : Cd(pf, lb, sel, pt)
{
    strcpy(song, fn);
}

Classic::Classic()
{
}

void Classic::Report() const
{
    std::cout << "Song: " << song << std::endl;
    Cd::Report();
}


