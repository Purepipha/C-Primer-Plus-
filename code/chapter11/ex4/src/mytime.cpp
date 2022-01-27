// mytime.cpp -- implementing Time methods
#include <iostream>
#include "mytime.h"

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

Time operator+(const Time & t1, const Time & t2) 
{
    Time sum;
    sum.hours = t1.hours;
    sum.minutes = t2.minutes;
    sum.AddMin(t2.minutes);
    sum.AddHr(t2.hours);
    return sum;
}

Time operator-(const Time & t1, const Time & t2)
{
    Time diff;
    diff.minutes = t1.minutes - t2.minutes;
    diff.hours = t1.hours - t2.hours;
    if(diff.minutes < 0)
    {
        diff.minutes = 60 - diff.minutes;
        diff.hours -= 1;
    }
    return diff;
}

Time operator*(const Time & t, double n)
{
    Time result;
    long totalminutes = (t.hours * 60 + t.minutes) * n;
    result.minutes = totalminutes % 60;
    result.hours = totalminutes / 60;
    return result;
}

std::ostream & operator<<(std::ostream & os,const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;  // is necessary
}