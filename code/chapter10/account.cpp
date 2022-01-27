// account.cpp -- Account member function
#include <iostream>
#include "account.h"

BankAccount::BankAccount()
{
}

BankAccount::BankAccount(const std::string & name, const std::string & acc_num, double cash)
{
    name_ = name;
    acc_num_ = acc_num;
    deposit_ = cash;
}

BankAccount::~BankAccount()
{
}

void BankAccount::show_account()
{
    using std::cout;
    cout << "Name: " << name_ << ", account number: " 
         << acc_num_ << ", deposit: " << deposit_ << '\n';
}

void BankAccount::deposit_in(double cash)
{
    using std::cout;
    if(cash < 0)
    {
        cout << "The number of cash you deposit is negative; "
             << "transcation is aborted.\n";
    }
    else
        deposit_ += cash;
}

void BankAccount::deposit_out(double cash)
{
    using std::cout;
    if(cash < 0)
    {
        cout << "The number of cash you deposit is negative; "
             << "transcation is aborted.\n";
    }
    else if(cash > deposit_)
    {
        cout << "You can't take the cash morn than you have!"
             << "Transcation is aborted.\n";
    }
    else
        deposit_ -= cash;
}