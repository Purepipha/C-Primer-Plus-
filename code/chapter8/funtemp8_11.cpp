// funtemp8_11.cpp -- using a function template
#include<iostream>
template<typename T>
void Swap(T & a, T & b);
int main()
{
    using namespace std;
    int i = 20;
    int j = 10;
    cout << "i, j = " << i << ", " << j << ".\n";
    Swap(i,j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    double x = 23.6;
    double y = 52.0;
    cout << "x, y = " << x << ", " << y << ".\n";
    Swap(x,y);
    cout << "Now x, y = " << x << ", " << y << ".\n";
    return 0;
}

template<typename T>
void Swap(T & a, T & b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}