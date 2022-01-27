// stock20.h -- augment version
// verson 20
#ifndef STOCK20_H_
#define STOCK20_H_

#include<string>

class Stock
{
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot(){ total_val = shares * share_val; }

    public:
        Stock();
        Stock(const std::string co, long n = 0.0, double pr = 0.0);
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show()const;
        const Stock & topval(const Stock & s) const;
        const std::string & getcompany() const{return company;}
        long getshares() const{return shares;}
        double getshares_val() const {return share_val;}
        double gettotal_val() const {return total_val;}
};
#endif