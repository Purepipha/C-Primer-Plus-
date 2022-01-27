// ex4.cpp -- calculate profit
#include<iostream>
const int money_init = 100;
int main()
{
    using namespace std;
    double profit_c = money_init;
    int profit_d = money_init;
    int year = 0;
    while(profit_c<=profit_d)
    {
        ++ year;
        profit_d += 10; // mistake profit_d += 10 * year
        profit_c += 0.05 * profit_c;
    }
    cout << "After " << year << " years, ";
    cout << "Cleo over Daphne.\n";
    cout << "Cleo's profit: " << profit_c << endl;
    cout << "Daphne's profit: " << profit_d << endl;
    return 0;
}