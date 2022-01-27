// exc_mean.h -- definition of exception of hmean() and gmean()
#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_
#include <string>
#include <stdexcept>
#include <iostream>

class bad_meanABC : public std::logic_error
{
private:
    double a_;
    double b_;
public:
    bad_meanABC(double a = 0, double b = 0, const std::string & s = "function name")
        : logic_error(s), a_(a), b_(b) { }
    double a_val() const { return a_; }
    double b_val() const { return b_; }
    virtual ~bad_meanABC() { }
    virtual void mesg() const = 0;
};

class bad_hmean : public bad_meanABC
{
public:
    bad_hmean(double a = 0, double b = 0, const std::string & s = "hmean") :
    bad_meanABC(a,b, s) { }
    ~ bad_hmean() { }
    virtual void mesg() const;
};

class bad_gmean : public bad_meanABC
{
public:
    bad_gmean(double a = 0, double b = 0, const std::string & s = "gmean") :
    bad_meanABC(a,b, s) { }
    ~ bad_gmean() { }
    virtual void mesg() const;
};
#endif

inline void bad_hmean::mesg() const
{
    std::cout << logic_error::what() 
        << "(" << a_val() << ", " << b_val() << "): ";
    std::cout << "Invalid argument a = -b \n";
}

inline void bad_gmean::mesg() const
{
    std::cout << logic_error::what() 
        << "(" << a_val() << ", " << b_val() << "): ";
    std::cout << "Arguments a b should be >=0\n";
}