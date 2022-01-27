// ex5.cpp -- calculating income tax
#include<iostream>

// tax rate
const double rate[4] = {0, 0.10, 0.15, 0.20};
const double tax_p[3]= {5000, 15000, 35000};

double cal_tax(double income);

int main()
{
    using namespace std;
    double income, tax;
    cout << "Enter your income, you can get your income tax.\n"
            "type negative digits or no-numbers to terminate.\n";
    cout << "Enter your income: ";
    while((income >= 0) && (cin >> income))
    {
        tax = cal_tax(income);
        cout << "The tax of " << income << " tvarps is " << tax << " tvarps.\n";
        cout << "Enter next income: ";
    }
    cout << "Bye!\n";
    return 0;
}

double cal_tax(double income)
{
    double tax;
    if(income <= tax_p[0])
        tax = income * rate[0];
    else if(income > tax_p[0] && income <= tax_p[1])
        tax = (income - tax_p[0]) * rate[1];
    else if(income > tax_p[1] && income <= tax_p[2])
        tax = (income - tax_p[1]) * rate [2] + (tax_p[1] - tax_p[0]) * rate[1];
    else if(income > tax_p[2])
        tax = (tax_p[1] - tax_p[0]) * rate[1] + (tax_p[2] - tax_p[1]) * rate[2] + (income - tax_p[2]) * rate[3];
    return tax;
}

