// strctptr.cpp -- function with point to structure arguments
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

void show_polar(const polar *ptrp);
void rect_to_polor(const rect *ptrr, polar *ptp);

int main()
{
    using namespace std;
    rect rplace;
    polar pplace;
    cout << "Enter the x and y values: ";
    while(cin >> rplace.x >> rplace.y)
    {
        rect_to_polor(&rplace, &pplace);
        show_polar(&pplace);
        cout << "Next two numbers(q to quit): ";
    }
    cout << "Done.\n";
    return 0;
}

void show_polar(const polar *ptrp)
{
    using namespace std;
    cout << "Distance: " << ptrp->distance << ", angle: " << ptrp->angle << endl;
}

void rect_to_polor(const rect *ptrr, polar * ptrp)
{
    const double Rad_to_deg = 57.29577951;
    ptrp->distance = sqrt(ptrr->x * ptrr->x + ptrr->y * ptrr->y);
    ptrp->angle = atan2(ptrr->y, ptrr->x) * Rad_to_deg;
}