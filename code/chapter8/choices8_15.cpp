// choices8_15.cpp -- choose a template
#include<iostream>

template<class T>
T Lesser(T a, T b) //#1
{
    return a < b ? a: b;
}

int Lesser(int a, int b) //#2
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a: b;
}

int main()
{
    using namespace std;
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << Lesser(m,n) << endl;        // use #2 
    cout << Lesser(x,y) << endl;        // use #2 with double
    cout << Lesser<>(m,n) << endl;      // use #1 with int
    cout << Lesser<int>(x,y) << endl;   // use #1
    return 0;
}