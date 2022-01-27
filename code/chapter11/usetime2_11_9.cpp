// usetime2_11_9.cpp -- using the third draft of the Time class
// compile usetime0.cpp and mytime0.cpp together
#include <iostream>
#include "mytime2.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    Time weeding(4,35);
    Time waxing(2,47);
    Time total,diff,adjusted;
    cout << "weeding time = ";
    weeding.Show();
    cout << endl;

    cout << "waxing time = ";
    waxing.Show();
    cout << endl;

    total = weeding + waxing;
    cout << "total work time = ";
    total.Show();
    cout << endl;

    diff = weeding - waxing;
    cout << "weeding time - waxing time = ";
    diff.Show();
    cout << endl;

    adjusted = total * 1.5;
    cout << "adjusted work time = ";
    adjusted.Show();
    cout << endl;

    return 0;
}