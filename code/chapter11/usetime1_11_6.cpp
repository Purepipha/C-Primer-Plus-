// usestime1_11_6.cpp -- using the second draft of the Time class
// compile mytime1.cpp and mytime0.cpp together
#include <iostream>
#include "mytime1.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time total;
    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    return 0;
}