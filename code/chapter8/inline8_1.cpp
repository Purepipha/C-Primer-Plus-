// inline8_1.cpp -- using an inline function
#include<iostream>

inline double squre(double x){return x * x;}

int main()
{
    using namespace std;
    double a, b;
    double c = 13.0;

    a = squre(5.0);
    b = squre(5.5 + 6.5);
    cout << "a = " << a << ", " << "b = " << b << endl;
    cout << "c = " << c;
    cout << ", c suqred = " << squre(c++) << endl; // c++ is 169, ++c is 196
    cout << "Now c = " << c << endl;
    return 0;
}