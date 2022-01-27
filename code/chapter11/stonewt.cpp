// stonewt.cpp -- Stonewt methods
#include <iostream>
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;     // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs -int(lbs);
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

// default constructor, wt = 0
Stonewt::Stonewt()
{
    stone = pds_left = pounds = 0;
}

Stonewt::~Stonewt()         // destructor
{
}
// show weight in stones
void Stonewt::show_stn() const
{
    std::cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const
{
    std::cout << pounds << " pounds\n";
}