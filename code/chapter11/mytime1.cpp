// mytime0.cpp -- implementing Time methods
#include <iostream>
#include "mytime1.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    if(minutes > 60)
    {
        hours += minutes / 60;
        minutes %= 60;
    }
}

void Time::AddHr(int h)
{
    hours += h;
}

Time Time::operator+(const Time & t) const
{
    Time temp;
    temp.hours = hours;
    temp.minutes = minutes;
    temp.AddMin(t.minutes);
    temp.AddHr(t.hours);
    return temp;
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
}