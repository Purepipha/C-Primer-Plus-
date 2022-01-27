// ex7.cpp -- set output format
#include <iostream>
#include <iomanip>

int main()
{
    using namespace std;
    string name;
    double wages_h;
    double hours;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your hourly wages: ";
    cin >> wages_h;
    cout << "Enter numbers of hours: ";
    cin >> hours;
    cout << "First format:\n";
    cout << setw(30) << name << ": $" << fixed 
         << setw(10) << setprecision(2) << wages_h << ":"
         << setw(8) << setprecision(1) << hours << endl;
    cout << "Second format:\n";
    cout << left << setw(30) << name << ": $" << fixed 
         << setw(10) << setprecision(2) << wages_h << ":"
         << setw(8) << setprecision(1) << hours << endl;

    return 0;
}