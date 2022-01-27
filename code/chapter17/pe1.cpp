// pe1.cpp -- calculate the number out input character before first $
#include <iostream>

int main()
{
    using namespace std;
    char ch;
    int ct = 0;
    while (cin.peek() != '$')
    {
        ct++;
        cin.get(ch);            // cin >> ch is wrong
    }
    cout << "The number of input character before first $ is "
         << ct << endl;
    cin.get(ch);
    cout << "The character in stream is " << ch << endl;
    return 0;
}