// wine.cpp -- methods for Wine class
#include <iostream>
#include "winei.h"

// constructor
Wine::Wine(const char * l, int y) : std::string(l), years(y),
Pair(ArrayInt(y),ArrayInt(y)) { }

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
         : std::string(l), years(y), 
         Pair(ArrayInt{yr,(long long unsigned int)y}, ArrayInt{bot, (long long unsigned int)y}) { }

// input the bottles
void Wine::GetBottles()
{
    std::cout << "Enter " << Label() << " data for " 
              << years << " year(s): " << std::endl;
    for (int i = 0; i < years; i++)
    {
        std::cout << "Enter year: ";
        std::cin >> Pair::first().operator[](i);
        std::cout << "Enter bottles for that year: ";
        std::cin >> Pair::second().operator[](i);
    }
    // get all '\n'
    while (std::cin.get() != '\n')
        continue;
}

int Wine::sum() const
{
    return Pair::second().sum();
}

void Wine::Show() const
{
    std::cout << "Wine: " << Label() << std::endl;
    std::cout << "\t\tYear\tBottles" << std::endl; 
    for (int i = 0; i < years; i++)
        std::cout << "\t\t" << Pair::first()[i] 
                  << "\t" << Pair::second()[i] << std::endl;
}