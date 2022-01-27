// ex4.cpp -- main() of sale.cpp
#include<iostream>
#include"sale.h"



int main()
{
    using namespace SALES;
    using std::cout;
    Sales s1,s2;
    double arr[6] = {1111.1, 666.6, 999.9, 333.3, 2222.2, 1234.5};
    setSales(s1);
    showSales(s1);
    setSales(s2, arr, 6);
    showSales(s2);
    cout << "Bye\n";
    return 0;
}