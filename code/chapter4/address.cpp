// address.cpp -- using & to find addresses
#include<iostream>
int main()
{
    using namespace std;
    int donuts = 6;
    double cups = 4.5;
    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts << endl;
// Note: You may need to use unsigned(&donuts)
    cout << "cups value = " << cups;
    cout << " and cups address = " << &cups << endl;
    return 0;
}