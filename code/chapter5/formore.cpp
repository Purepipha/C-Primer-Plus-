// formore.cpp -- more looping with for
#include<iostream>
const int arrsize = 16;
int main()
{
    using namespace std;
    long long factories[arrsize]; // need consider
    factories[1] = factories[0] = 1LL;
    for(int i = 2;i < arrsize; i++)
        factories[i] = factories[i-1] * i;
    for(int i = 0;i < arrsize;i++)
        cout << factories[i] << " ";
    return 0;
}