// error4_15_11.cpp -- using exception classes
#include <iostream>
#include <cmath>    // or math.h, unix users may need -lm flag
#include "exc_mean.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two nembers: ";
    while (cin >> x >> y)
    {
        try{
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << z << endl;
            cout << "Geimetric mean of " << x << " and " << y
                 << " is " << gmean(x,y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }
        catch (bad_hmean & bh)
        {
            bh.mesg();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean & bg)
        {
            cout << bg.mesg();
            cout << "Values used: " << bg.v1 << ", "
                 << bg.v2 << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a,b);
    else
        return 2 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a,b);
    else
        return sqrt(a * b);
}