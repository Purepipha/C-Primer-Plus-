// mytime3.cpp -- implementing Time methods
#include <iostream>
#include "mytime3.h"

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
    Time sum;
    sum.hours = hours;
    sum.minutes = minutes;
    sum.AddMin(t.minutes);
    sum.AddHr(t.hours);
    return sum;
}

Time Time::operator-(const Time & t) const
{
    Time diff;
    diff.minutes = minutes - t.minutes;
    diff.hours = hours - t.hours;
    if(diff.minutes < 0)
    {
        diff.minutes = 60 - diff.minutes;
        diff.hours -= 1;
    }
    return diff;
}

Time Time::operator*(double n) const
{
    Time result;
    long totalminutes = (hours * 60 + minutes) * n;
    result.minutes = totalminutes % 60;
    result.hours = totalminutes / 60;
    return result;
}

std::ostream & operator<<(std::ostream & os,const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;  // is necessary
}