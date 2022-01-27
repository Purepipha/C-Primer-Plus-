// complex0.h -- defination of complex class
#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>
using std::ostream;
using std::istream;
class complex
{
private:
    double real;
    double imaginary;
public:
    complex(double i, double j);
    complex();
    ~complex();
    // overloading operator + - * and ~
    complex operator+(const complex & c) const;
    complex operator-(const complex & c) const;
    complex operator*(const complex & c) const;
    complex operator~() const;

    // friend 
    friend complex operator*(double n, const complex & c);
    friend istream & operator>>(istream & os, complex & c);
    friend ostream & operator<<(ostream & os, const complex & c);
};
#endif