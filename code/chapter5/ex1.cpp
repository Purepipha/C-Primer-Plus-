// ex1.cpp -- calculate the sum of between two integers' all integer
#include<iostream>
int main()
{
    using namespace std;
    int i,j;
    int sum = 0;
    cout << "Enter two integers: ";
    cin >> i >> j;
    for(;i<=j;i++)
        sum += i;
    cout << "The sum of between two integers' all integers is ";
    cout << sum << endl;
    return 0;
}