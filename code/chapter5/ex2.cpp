// ex2.cpp -- calculate 100!
#include<iostream>
#include<array>
const int arsize = 101;
int main()
{
    using namespace std;
    array<long double,arsize> factories;
    factories[0] = 1;
    factories[1] = 1;
    for(int i = 2; i < arsize; ++i)
        factories[i] = factories[i-1] * i;
    cout << "100! = " << factories[100] << endl;
    return 0;
}