// ex6.cpp -- cout a integer in dec oct and hex
#include <iostream>
#include <iomanip>

int main()
{
    using namespace std;
    int n;
    cout << "Enter an integer: ";
    cin >> n;
// use ios_base::fmtflags
    cout.setf(ios_base::showbase);
    cout.width(15);
    cout << n;
    // cout.setf(ios_base::oct);       // is not work, add ios::field, can't find the field
    cout.width(15);
    cout << oct << n;
    cout.width(15);
    cout.setf(ios_base::hex);
    cout << hex << n << endl;
    cout.unsetf(ios_base::showbase);
// use iomanip
    cout << showbase << setw(15) << dec << n
         << setw(15) << oct << n
         << setw(15) << hex << n << endl << noshowbase;
    return 0;
}