// atrctfun.cpp -- function with a structure argument
#include<iostream>
#include<cmath>

struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

void show_polar(polar p);
polar rect_to_polor(rect r);

int main()
{
    using namespace std;
    rect rplace;
    polar pplace;
    cout << "Enter the x and y values: ";
    while(cin >> rplace.x >> rplace.y)
    {
        pplace = rect_to_polor(rplace);
        show_polar(pplace);
        cout << "Next two numbers(q to quit): ";
    }
    cout << "Done.\n";
    return 0;
}

void show_polar(const polar p)
{
    using namespace std;
    cout << "Distance: " << p.distance << ", angle: " << p.angle << endl;
}

polar rect_to_polor(rect r)
{
    polar answer;
    const double Rad_to_deg = 57.29577951;
    answer.distance = sqrt(r.x * r.x + r.y * r.y);
    answer.angle = atan2(r.y,r.x) * Rad_to_deg;
    return answer;
}