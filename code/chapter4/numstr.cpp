// numestr.cpp - - following number input with line input
#include<iostream>
int main()
{
    using namespace std;
    cout << "What year was your house bulit?\n";
    int year;
    cin >> year; // or (cin >> year).get();
    cin.get();
    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address,80);
    cout << "Year built: " << year << endl;
    cout << "Street address: " << address << endl;
    return 0;
}