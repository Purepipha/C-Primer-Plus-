// usestock0.cpp -- the client program
// compile with stock00.cpp
#include<iostream>
#include"stock00.h"
int main()
{
    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("NanaSmart", 20, 12.5);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(30000, 40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(30000, 0.125);
    fluffy_the_cat.show();
    return 0;
}