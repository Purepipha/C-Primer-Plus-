// ex5.cpp -- calculate the n!
#include<iostream>

long long cal_factorial(int n);

int main()
{
    using namespace std;
    int num;
    long long factorial;
    cout << "Enter the number(enter q to quit): ";
    while(cin >> num)
    {
        factorial = cal_factorial(num);
        cout << num << "! = " << factorial << endl;
        cout << "Enter next number(enter q to quit): ";
    }
    cout << "Done\n";
    return 0;
}
long long cal_factorial(int n)
{
    long long result = 1;
    if(n > 1)
        result = n * cal_factorial(n-1);
    else if(n == 1 || n ==0)
        result *=1;
    return result;
}