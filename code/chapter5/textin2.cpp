// textin2.cpp -- using cin.get(char)
#include<iostream>
int main()
{
    using namespace std;
    char ch;
    int i = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch);
    while(ch != '#')
    {
        i++;
        cout << ch;
        cin.get(ch);
    }
    cout << endl << "You have entered " << i << " characters.\n";
    return 0;
}