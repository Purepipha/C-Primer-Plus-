// use_new.cpp -- using the new operator
#include<iostream>
int main()
{
    using namespace std;
    int nigthts = 1001;
    int* pt = new int;
    *pt = 1001;
    
    cout << "nights value = " << nigthts 
         << ": location = " << &nigthts << endl;
    cout << "int ";
    cout << "value = " << *pt << ": location = " << pt << endl;

    double* pd = new double;
    *pd = 100000001.0;

    cout << "double ";
    cout << "value = " << *pd << ": location = " << pd << endl;
    cout << "location of pointer pt: " << &pt <<endl;
    cout << "location of pointer pd: " << &pd <<endl;
    cout << "size of pt = " << sizeof(pt);
    cout << " size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof(pd);
    cout << " size of *pd = " << sizeof(*pd) << endl;
    return 0;
}