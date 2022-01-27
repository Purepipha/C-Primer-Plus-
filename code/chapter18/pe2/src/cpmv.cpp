// cpmv.cpp -- methods for Cpmv class
#include "cpmv.h"

Cpmv::Cpmv()
{
    std::cout << "Called Cpmv()\n";
    pi = new Info;
}

Cpmv::Cpmv(std::string q, std::string z)
{
    std::cout << "Called Cpmv(string q, string z)\n";
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp)
{
    std::cout << "Called Cpmv(const Cpmv & cp)\n";
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv && mv)
{
    std::cout << "Called Cpmv(Cpmv && mv)\n";
    pi = new Info;
    pi = mv.pi;
    mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
    std::cout << "Called ~Cpmv()\n";
    delete pi;
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{
    std::cout << "Called operator=(const Cpmv & cp)\n";
    if (this == &cp)
        return *this;
    delete pi;
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
    std::cout << "Called operator=(Cpmv && mv)\n";
    if (this == &mv)
        return *this;
    delete pi;
    pi = new Info;
    pi = mv.pi;
    mv.pi = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
    std::cout << "Called operator+(const Cpmv & obj) const\n";
    Cpmv temp;
    temp.pi->qcode = pi->qcode + obj.pi->qcode;
    temp.pi->zcode = pi->zcode + obj.pi->zcode;
    return temp;
}

void Cpmv::Display() const
{
    std::cout << "Called Display() const\n";
    std::cout << pi->qcode << '\t';
    std::cout << pi->zcode << '\n';
}