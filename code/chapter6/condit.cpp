// condit.cpp -- use the conditional opreator
#include<iostream>
int main()
{
    using namespace std;
    int a,b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "The large number is " << (a > b ? a: b) << endl;
    return 0;
}