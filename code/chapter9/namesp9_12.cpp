// namesp9_12.cpp -- namespaces
#include<iostream>
#include"namesp.h"

namespace pers
{
    using std::cout;
    using std::cin;
    void getPerson(Person & p)
    {
        cout << "Enter first name: ";
        cin >> p.fname;
        cout << "Enter last name: ";
        cin >> p.lname;
    }
    void showPerson(const Person & p)
    {
        cout << p.lname << ", " << p.fname;
    }
}

namespace debts
{
    void getDebt(Debt & d)
    {
        getPerson(d.name);
        std::cout << "Enter debt: ";
        std::cin >> d.amount;
    }

    void showDebt(const Debt & d)
    {
        showPerson(d.name);
        cout << ": $ " << d.amount << std::endl;
    }
    double sumDebts(const Debt ar[], int n)
    {
        double sum = 0;
        for(int i = 0; i < n; i++)
            sum += ar[i].amount;
        return sum;
    }
}