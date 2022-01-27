// textin3.cpp -- reading chars to end of file
#include<iostream>
int main()
{
    using namespace std;
    char ch;
    int i = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch);
    while(cin.fail() == false)
    {
        i++;
        cout << ch;
        cin.get(ch);
    }
    cout << endl << "You have entered " << i << " characters.\n";
    return 0;
}