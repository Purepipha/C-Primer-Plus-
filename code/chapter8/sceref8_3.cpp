// sceref8_3.cpp -- defining and using a reference
#include<iostream>
int main()
{
    using namespace std;
    int rats = 101;
    int & rodents = rats;

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address  = " << &rats;
    cout << ", rodents address = " << &rodents << endl;
    
    int business = 50;
    rodents = business;
    cout << "business = " << business;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "business address = " << &business;
    cout << ", rats address  = " << &rats;
    cout << ", rodents address = " << &rodents << endl;
}