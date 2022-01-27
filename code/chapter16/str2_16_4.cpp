// str2_16_4.cpp -- capacity() and reverse()
#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string empty;
    string small = "bit";
    string lager = "Elephants are a girl's best friend";
    cout << lager << endl;
    cout << "Size:\n";
    cout << "\tempty: " << empty.size() << endl;
    cout << "\tsmall: " << small.size() << endl;
    cout << "\tlarger: " << lager.size() << endl;
    cout << "Capacities:\n";
    cout << "\tempty: " << empty.capacity() << endl;
    cout << "\tsmall: " << small.capacity() << endl;
    cout << "\tlarger: " << lager.capacity() << endl;
    lager += '!';
    cout << "\tlarger: " << lager.capacity() << endl;
    empty.reserve(50);
    cout << "Capacity after empty.reserve(50): ";
    cout << empty.capacity() << endl;
    return 0;
}