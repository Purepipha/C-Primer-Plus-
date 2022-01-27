// stock20.cpp --augment version
// version 20
#include<cstring>
#include"stock20.h"

// constructors
Stock::Stock()
{
    company = new char[1];
    company[0] = '\0';
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * str, long n, double pr)
{
    company = new char[strlen(str) + 1];
    strcpy(company, str);
    if(n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares will be set to 0.\n";
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}
Stock::Stock(const Stock & s)
{
    company = new char[strlen(s.company) + 1];
    strcpy(company, s.company);
    shares = s.shares;
    share_val = s.share_val;
    set_tot();
}
Stock::~Stock()
{
    delete [] company;
}

void Stock::buy(long num, double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else
        shares += num;
    share_val = price;
    set_tot();
}

void Stock::sell(long num, double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares sold can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else if(num > shares)
    {
        std::cout << "You can't sell more than you have! "
                   << "Transaction is aborted.\n";
    }
    else
        shares -= num;
    share_val = price;
    set_tot();
}

void Stock::update(double price)
{
    share_val = price;
}

void Stock::show()const
{
    using std::cout;
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company
        << "Shares: " << shares << '\n';
    cout << "   Share Price: $" << share_val;
    // set format to #.##
    cout.precision(2);
    cout << "   Total Worth: $" << total_val << '\n';

    // restore orignal format

    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topval(const Stock & s) const
{
    return s.total_val > total_val ? s : *this;
}

std::ostream & operator<<(std::ostream & os, const Stock & s)
{
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig =
        os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);

    os << "Company: " << s.getcompany()
        << "Shares: " << s.shares << '\n';
    os << "   Share Price: $" << s.share_val;
    // set format to #.##
    os.precision(2);
    os << "   Total Worth: $" << s.total_val << '\n';

    // restore orignal format

    os.setf(orig,ios_base::floatfield);
    os.precision(prec);
    return os;
}

Stock & Stock::operator=(const Stock & s)
{
    if(this == &s)
        return *this;
    company = new char[strlen(s.company) + 1];
    strcpy(company, s.company);
    shares = s.shares;
    share_val = s.share_val;
    set_tot();
    return *this;
}