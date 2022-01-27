// ex4_useSales.cpp -- using namespace and class
// compile with sale.cpp

#include <iostream>
#include "sale.h"

int main()
{
    using namespace SALES;
    using std::cout;
    Sales s1;
    double arr[6] = {1111.1, 666.6, 999.9, 333.3, 2222.2, 1234.5};
    Sales s2 = Sales(arr, 6);
    s1.ShowSales();
    s2.ShowSales();
    cout << "Bye\n";
    return 0;
}