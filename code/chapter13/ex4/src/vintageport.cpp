// vintageport.cpp -- methods for VintagePort class
#include <cstring>
#include "vintageport.h"
// methods for Port class
Port::Port(const char * br, const char * st, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}

Port::Port(const Port & p)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
    if (this == &p)
        return *this;
    else
    {
        delete [] brand;
        brand = new char[strlen(p.brand) + 1];
        strcpy(brand, p.brand);
        strcpy(style, p.style);
        bottles = p.bottles;
        return *this;
    }
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    if (b <= bottles)
        bottles -= b;
    else
        cout << b << " > " << bottles << endl;
    return *this;
}

void Port::Show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

// methods for VintagePort class
VintagePort::VintagePort() : Port("none","vintage")
{
    nickname = new char[5];
    strcpy(nickname, "none");
    year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br, "vintage", b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (this == &vp)
        return *this;
    else
    {
        Port::operator=(vp);
        delete [] nickname;
        nickname = new char[strlen(vp.nickname) + 1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
        return *this;
    }
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Nick Name: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os << (const Port &)vp << ", " << vp.nickname << ", " << vp.year;
    return os;
}