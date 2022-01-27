// pe4.cpp -- use lambda function
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

// has name lambda function
auto outint = [](int n) { std::cout << n << " "; };

int main()
{
    using std::list;
    using std::cout;
    using std::endl;

    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada{vals, vals+10};  // range constructor
    list<int> etcetera(vals, vals+10);
// C++11 can use the following instead
    // list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    // list<int> etcetera{50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    cout << "Original list:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    yadayada.remove_if([](int x){ return x > 100; });
    etcetera.remove_if([](int x){ return x > 200; });
    cout << "Trimmed list:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    return 0;
}