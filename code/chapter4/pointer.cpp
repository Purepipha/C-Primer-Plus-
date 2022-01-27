// pointer.cpp -- our first pointer variable
#include<iostream>
int main()
{
    using namespace std;
    int update = 9;
    int * p_update ;
    p_update = &update;

    cout << "Value: update = " << update;
    cout << ", *p_update = " << *p_update << endl;

    cout << "Addresses: &update = " << &update;
    cout << ", p_update = " << p_update << endl;

    *p_update = *p_update + 1;
    cout << "Now update = " << update << endl;
    return 0;
}