// usetime3_11_12.cpp -- using the third draft of the Time class
// compile usetime3.cpp and mytime0.cpp together
#include "mytime.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    Time weeding(4,35);
    Time waxing(2,47);
    Time total,diff,adjusted;
    cout << "weeding time = " << weeding << endl;
    
    cout << "waxing time = " << waxing << endl;

    total = weeding + waxing;
    cout << "total work time = " << total << endl;

    diff = weeding - waxing;
    cout << "weeding time - waxing time = " << diff << endl;

    adjusted = 1.5 * total;
    cout << "adjusted work time = " << adjusted << endl;

    return 0;
}