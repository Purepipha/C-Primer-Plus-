// vector.cpp -- methods for Vector class
#include "vector.h"
using std::cout;
namespace VECTOR
{
    const double Rad_to_deg = 45 / atan(1.0);
    // private member function
    void Vector::set_ang()
    {
        if(x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y,x);
    }
    Vector::Vector()        // default constructor
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, MODE form)
    {
        mode = form;
        if(mode == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if(mode == POL)
        {
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() --";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0;
            mode = RECT;
        }
    }
    // reset the Vector
    void Vector::reset(double n1, double n2, MODE form)
    {
        mode = form;
        if(mode == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if(mode == POL)
        {
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() --";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0;
            mode = RECT;
        }
    }

    Vector::~Vector()           // destructor
    {
    }

    // operator overloading
    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    Vector operator*(double n, const Vector & v)
    {
        return v * n;
    }

    ostream & operator<<(ostream & os, const Vector & v)
    {
        if(v.mode == Vector::RECT)
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if(v.mode == Vector::POL)
            os << "(m,a) = (" << v.mag << ", " << v.ang << ")";
        else
            os << "Vector object mode is invalid";
        return os;
    }

}   // end namespace VECTOR