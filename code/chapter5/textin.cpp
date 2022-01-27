// textin.cpp -- reading chars with a while loop
#include<iostream>
int main()
{
    using namespace std;
    char ch;
    int i = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;
    while(ch != '#')
    {
        i++;
        cout << ch;
        cin >> ch;
    }
    cout << endl << "You have entered " << i << " characters.\n";
    return 0;
}