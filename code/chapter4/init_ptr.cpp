// init_ptr.cpp -- intialize a pointer
#include<iostream>
int main()
{
    using namespace std;
    int higgens = 5;
    int* ptr = &higgens;
    cout << "Value of higgens: " << higgens
         << ", Addresses of higgens: " << &higgens << endl;
    cout << "Value of *ptr: " << *ptr
         << ", Value of ptr: " << ptr << endl;
    return 0;
}