// ex6.cpp --calculate three year sales of book
#include<iostream>
#include<string>
const int Months = 12;
const int Years = 3;
int main()
{
    using namespace std;
    string month[Months]={"January", "February","March","April","May",
    "June","July","August","September","October","November","December"};
    const char* year[Years] = {"2019", "2020", "2021"};
    // const char *month[Months] = {"January", "February","March","April","May",
    // "June","July","August","September","October","November","December"};
    long sum_year = 0;
    long sum = 0;
    int sale[Months][Years];
    for(int i = 0; i < Years; ++i)
    {
        for(int j = 0; j < Months; ++j)
        {
            cout << "Enter the amount of sale in " << year[i] << ",";
            cout << month[j] << ": ";
            cin >> sale[i][j];
            sum_year += sale[i][j];
        }
        cout << "The sales in " << year[i] << ": " << sum_year << endl;
        sum += sum_year;
        sum_year = 0;
    }
    cout << "The sales of three years: " << sum << endl;
    return 0;
}