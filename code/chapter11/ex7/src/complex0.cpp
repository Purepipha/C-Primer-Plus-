// complex0.cpp -- methods for complex class
#include "complex0.h"

// constructor
complex::complex(double i, double j)
{
    real = i;
    imaginary = j;
}

complex::complex()  // default 
{
    real = imaginary = 0.0;
}

// deconstructor
complex::~complex()
{
}

// overloading operator
complex complex::operator+(const complex & c) const
{
    return complex(real + c.real, imaginary + c.imaginary);
}

complex complex::operator-(const complex & c) const
{
    return complex(real - c.real, imaginary - c.imaginary);
}

complex complex::operator*(const complex & c) const
{
    return complex(real * c.real - imaginary * c.imaginary, real * c.imaginary + imaginary * c.real);
}

complex complex::operator~() const
{
    return complex(real, -imaginary);
}

// friend
complex operator*(double n, const complex & c)
{
    return complex(n * c.real, n * c.imaginary);
}

std::istream & operator>>(std::istream & is, complex & c)
{
    std::cout << "real: ";
    if(is >> c.real)
    {
        std::cout << "imaginary: ";
        is >> c.imaginary;
    }
    return is;
}

std::ostream & operator<<(std::ostream & os, const complex & c)
{
    os << "(" << c.real << ", " << c.imaginary << "i)";
    return os;
}