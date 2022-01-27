// exc_mean.h -- class for exception of hmean and gmean
#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_
#include <stdexcept>
#include <iostream>
#include <string>

class bad_hmean : public std::logic_error
{
public:
    explicit bad_hmean(const std::string & s = "hmean(): Invalid argument a = -b")
         : logic_error(s) { }
    virtual const char * what();
    virtual ~bad_hmean() { }
};

class bad_gmean : public std::logic_error
{
public:
    explicit bad_gmean(const std::string & s = "gmean() : Arguments shoule be >= 0")
         : logic_error(s) { }
    virtual const char * what();
    virtual ~bad_gmean() { }
};

#endif

inline const char * bad_hmean::what()
{
    return logic_error::what();
}

inline const char * bad_gmean::what()
{
    return logic_error::what();
}