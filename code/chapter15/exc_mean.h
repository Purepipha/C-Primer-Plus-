// exc_mean.h -- excpetion classes for hmean(), gmean()
#include <iostream>

class bad_hmean
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) { }
    void mesg();
};

class bad_gmean
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) { }
    const char * mesg();
};

inline void bad_hmean::mesg()
{
    std::cout << "hmean(" <<v1 << ", " << v2 << "): "
              << "invalid arguments a = -b\n";
}

inline const char * bad_gmean::mesg()
{
    return "gmean() arguments shoule be >= 0\n";
}