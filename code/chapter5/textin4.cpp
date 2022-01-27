// textin4.cpp -- reading chars with cin.get()
#include<iostream>
int main()
{
    using namespace std;
    int ch;
    int count = 0;
    ch = cin.get();
    while(ch != EOF)
    {
        ++count;
        cout.put(ch);
        ch = cin.get();
    }
    cout << endl << count << " characters read\n";
    return 0;
}