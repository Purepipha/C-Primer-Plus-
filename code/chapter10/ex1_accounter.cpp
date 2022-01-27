// accounter.cpp -- test the class account
#include <iostream>
#include "account.h"


int main()
{
    using std::cout;
    using std::cin;
    BankAccount account;
    std::string name;
    std::string acc_num;
    double cash;
    cout << "Enter your name: ";
    getline(cin,name);
    cout << "Enter your account number: ";
    getline(cin,acc_num);
    cout << "Enter the cash: ";
    cin >> cash;
    account = BankAccount(name,acc_num,cash);
    account.show_account();
    cout << "Enter the cash you want to take in: ";
    cin >> cash;
    account.deposit_in(cash);
    account.show_account();
    cout << "Enter the cash you want to take out: ";
    cin >> cash;
    account.deposit_out(cash);
    account.show_account();
    return 0;
}