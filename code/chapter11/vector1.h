// vector1.h -- Vector class with <<, mode state
// store Vector use x and y
#ifndef VECTOR1_H_
#define VECTOR1_H_
#include <iostream>
namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode{RECT, POL};
    // RECT for rectangular, POL for Polar modes
    private:
        double x;
        double y;
        Mode mode;
    // private methods for setting values;
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const {return x;}
        double yval() const {return y;}
        double magval() const;
        double angval() const;
        void polar_mode();                  // set mode to POL
        void rect_mode();                   // set mode to RECT
    // oprator overloading
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-()const;
        Vector operator*(double n) const;
    // friends
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & 
                operator<<(std::ostream & os, const Vector & v);
    };
     
}   // end namespace VECTOR

#endif