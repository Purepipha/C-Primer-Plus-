// if.cpp -- using the if statement
#include<iostream>
int main()
{
    using namespace std;
    char ch;
    int space = 0;
    int total = 0;
    ch = cin.get();
    while(ch != '.')
    {
        if(ch == ' ')
            ++space;
        ++total;
        ch = cin.get();
    }
    cout << space << "spaces, " << total;
    cout << " characters total in sentence\n";
    return 0;
}