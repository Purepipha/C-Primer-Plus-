// account.h -- class defination for Account
#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include<string>

class BankAccount
{
    private:
        std::string name_;
        std::string acc_num_;
        double deposit_;
    public:
        BankAccount();
        BankAccount(const std::string & name, const std::string & acc_num, double cash);
        ~BankAccount();
        void show_account();
        void deposit_in(double cash);
        void deposit_out(double cash);
};

#endif