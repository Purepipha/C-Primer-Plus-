// usestock10_9.cpp -- using the Stock class
// compile with stock20.cpp
#include<iostream>
#include"stock20.h"

const int STKS = 4;

int main()
{
// create an array of initialized objects
    Stock stocks[STKS] = 
    {
        Stock("NanaSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "Stock holding:\n";
    int st;
    for(st = 0; st < STKS; st++)
        std::cout << stocks[st];
// set pointer to first element
    const Stock * top = & stocks[0];
    for(st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
// now top points to the most valuable holding
    std::cout << "\nMost valuable holding:\n";
    std::cout << * top;
    return 0;
}