// vector.h -- defination of Vector class
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <cmath>
namespace VECTOR
{
    using std::sqrt;
    using std::sin;
    using std::cos;
    using std::atan;
    using std::atan2;
    using std::ostream;
    class Vector
    {
    public:
        enum MODE{RECT,POL};    // mode is public
    private:
        double x;
        double y;
        double mag;
        double ang;
        MODE mode;
        // set x and y from mag and ang
        void set_x(){ x = mag * cos(ang);}
        void set_y(){ y = mag * sin(ang);}
        // set mag and ang from x and y
        void set_mag(){mag = sqrt(x * x + y * y);}
        void set_ang();
    public:
        Vector();
        Vector(double n1, double n2, MODE form = RECT);
        ~Vector();
        void reset(double n1, double n2, MODE form = RECT);
        double x_val(){return x;}
        double y_val(){return y;}
        double mag_val(){return mag;}
        double ang_val(){return ang;}

        void polar_mode(){mode = POL;}
        void rect_mode(){mode = RECT;}

        // operator overloading
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        // friend
        friend Vector operator*(double n, const Vector & v);
        friend ostream & operator<<(ostream & os, const Vector & v);

    };  // end namespace VECTOR
    
    
}
#endif