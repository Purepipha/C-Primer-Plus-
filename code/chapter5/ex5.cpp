// ex5.cpp --calculate a year sales of book
#include<iostream>
#include<string>
const int Months = 12;
int main()
{
    using namespace std;
    string month[Months]={"January", "February","March","April","May",
    "June","July","August","September","October","November","December"};
    // const char *month[Months] = {"January", "February","March","April","May",
    // "June","July","August","September","October","November","December"};
    long sum = 0;
    int sale[Months];
    for(int i = 0; i < Months; ++i)
    {
        cout << "Enter the amount of sale in " << month[i] << ": ";
        cin >> sale[i];
        sum += sale[i];
    }
    cout << "The sale volume of this year is " << sum << endl;
    return 0;
}