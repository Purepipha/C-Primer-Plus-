// wine.cpp -- methods for Wine class
#include <iostream>
#include "winec.h"

// constructor
Wine::Wine(const char * l, int y) : name(l), years(y)
{
    pai.first().resize(years);
    pai.second().resize(years);
}

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
         : name(l), years(y)
{
    pai.first() = {yr, (long long unsigned int)years};
    pai.second() = {bot, (long long unsigned int)years};
}

// input the bottles
void Wine::GetBottles()
{
    std::cout << "Enter " << Label() << " data for " 
              << years << " year(s): " << std::endl;
    for (int i = 0; i < years; i++)
    {
        std::cout << "Enter year: ";
        std::cin >> pai.first().operator[](i);
        std::cout << "Enter bottles for that year: ";
        std::cin >> pai.second().operator[](i);
    }
    // get all '\n'
    while (std::cin.get() != '\n')
        continue;
}

int Wine::sum() const
{
    return pai.second().sum();
}

void Wine::Show() const
{
    std::cout << "Wine: " << Label() << std::endl;
    std::cout << "\t\tYear\tBottles" << std::endl; 
    for (int i = 0; i < years; i++)
        std::cout << "\t\t" << pai.first()[i] 
                  << "\t" << pai.second()[i] << std::endl;
}

// ps: Wine::years forget to intialize