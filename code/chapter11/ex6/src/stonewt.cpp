// stonewt.cpp -- Stonewt methods
#include "stonewt.h"


// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, MODE form)
{
    mode = form;        // is necessary
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, MODE form)
{
    mode = form;
    pounds = stn * Lbs_per_stn + lbs;
}

// construct Stonewt object form int pounds vlaue
Stonewt::Stonewt(int lbs, MODE form)
{
    mode = form;
    pounds = double(lbs);
}

// default constructor, wt = 0
Stonewt::Stonewt()
{
    pounds = 0;
}

Stonewt::~Stonewt()         // destructor
{
}
// get value
int Stonewt::stone_val() const
{
    return int(pounds) / Lbs_per_stn; 
}

double Stonewt::pds_left_val() const
{
    return int(pounds) % Lbs_per_stn + pounds -int(pounds);
}

double Stonewt::pounds_val() const
{
    return pounds;
}

int Stonewt::int_pounds_val() const
{
    return int(pounds);
}

// set mode
void Stonewt::pounds_mode()
{
    mode = POUNDS;
}

void Stonewt::int_pounds_mode()
{
    mode = INT_POUNDS;
}

void Stonewt::stone_mode()
{
    mode = STONE;
}

// operator + - *
Stonewt Stonewt::operator+(const Stonewt & st) const
{
    return Stonewt(pounds + st.pounds);
}

Stonewt Stonewt::operator-(const Stonewt & st) const
{
    return Stonewt(pounds - st.pounds);
}

Stonewt Stonewt::operator*(double n) const
{
    return Stonewt(n * pounds);
}

// friend
Stonewt operator*(double n, const Stonewt & st)
{
    return st * n;
}

bool operator==(const Stonewt & st1, const Stonewt & st2)
{
    return st1.pounds == st2.pounds ? true : false;
}
bool operator!=(const Stonewt & st1, const Stonewt & st2)
{
    return st1.pounds != st2.pounds ? true : false;
}
bool operator>(const Stonewt & st1, const Stonewt & st2)
{
    return st1.pounds > st2.pounds ? true : false;
}
bool operator<(const Stonewt & st1, const Stonewt & st2)
{
    return st1.pounds < st2.pounds ? true : false;
}
bool operator>=(const Stonewt & st1, const Stonewt & st2)
{
    return st1.pounds >= st2.pounds ? true : false;
}
bool operator<=(const Stonewt & st1, const Stonewt & st2)
{
    return st1.pounds <= st2.pounds ? true : false;
}

ostream & operator<<(ostream & os, const Stonewt & st)
{
    Stonewt::MODE mode;
    mode = st.mode;
    switch (mode)
    {
    case Stonewt::POUNDS: 
            os << "Double pounds: " << st.pounds << " pounds";
            break;
    case Stonewt::STONE:
            os << "Stone: " <<st.stone_val() << " stone, " << st.pds_left_val() << " pounds";
            break;
    case Stonewt::INT_POUNDS:
            os << "Int pounds: " << st.int_pounds_val() << " pounds";
            break;
    default:
            os << "Stonewt object mode is invalid";
            break;
    }
}
