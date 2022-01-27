// travel.cpp -- using struct with function
#include<iostream>
struct travel_time
{
    int hours;
    int mins;
};

void show_travel_time(const travel_time t1);
travel_time sum_travel_time(const travel_time t1, const travel_time t2);

int main()
{
    using namespace std;
    travel_time day1 = {5,45};
    travel_time day2 = {4,55};

    travel_time trip = sum_travel_time(day1, day2);
    cout << "Tow-day total: ";
    show_travel_time(trip);

    travel_time day3 = {4,32};
    cout << "Three-day total: ";
    show_travel_time(sum_travel_time(trip, day3));

}

void show_travel_time(travel_time t1)
{
    using namespace std;
    if(t1.mins >= 60)
    {
        t1.hours += (t1.mins / 60);
        t1.mins %= 60;
    }
    cout << "The travel time is " << t1.hours << " hours and "
         << t1.mins << " mininutes.\n";
}

travel_time sum_travel_time(const travel_time t1, const travel_time t2)
{
    travel_time t; // no point

    t.hours = t1.hours + t2.hours;
    t.mins = t1.mins + t2.mins;
    return t; // no point
}