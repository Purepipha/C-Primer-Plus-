// ex3.cpp -- calculate sum
#include<iostream>
int main()
{
    using namespace std;
    double i;
    double sum = 0;
    cout << "Enter a figure, input 0 will end.\n";
    cin >> i;
    while(i)
    {
        sum += i;
        cout << "sum = " << sum << endl;
        cin >> i;
    }
    return 0;
}