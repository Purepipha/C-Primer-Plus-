// plorg.cpp -- member funciton of class Plorg
// compile with ex7_useplorg.cpp

#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg()
{
}

Plorg::Plorg(const char * name, int CI)
{
    strcpy(name_, name);
    CI_ = CI;
}

void Plorg::setCI(int CI)
{
    CI_ = CI;
}

void Plorg::ShowPlorg() const
{
    std::cout << "Plorg name: " << name_ << ", CI = " << CI_ << '\n';
}

void Plorg::setname(const char * name)
{
    strcpy(name_,name);
}