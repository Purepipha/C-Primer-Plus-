// pe8.cpp -- use set and set_union
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

void show(const std::string & s) { std::cout << s << "; "; }
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::set;
    using std::string;
    using std::for_each;
// mat
    set<string> mat;
    string name;
    cout << "Dear mat, please enter your friend's name <quit to quit>: ";
    while (getline(cin, name) && name != "quit")
    {
        mat.insert(name);
        cout << "enter next name <quit to quit>: ";
    }
    cout << "Mat's friend list:\n";
    for_each(mat.begin(), mat.end(), show);
    cout << endl;
// pat
    set<string> pat;
    cout << "Dear pat, please enter your friend's name <quit to quit>: ";
    while (getline(cin, name) && name != "quit")
    {
        pat.insert(name);
        cout << "enter next name <quit to quit>: ";
    }
    cout << "Pat's friend list:\n";
    for_each(pat.begin(), pat.end(), show);
    cout << endl;
// set_union
    set<string> pm_union;
    std::set_union(mat.begin(), mat.end(), pat.begin(), pat.end(), 
        std::insert_iterator< set<string> >(pm_union, pm_union.begin()));
    cout << "Pat and Mat friend list:\n";
    for_each(pm_union.begin(), pm_union.end(), show);
    cout << endl;
    cout << "Done\n";
    return 0;
}