// cctypes.cpp -- using the cctype.h library
#include<iostream>
#include<cctype>
int main()
{
    using namespace std;
    char ch;
    int chars = 0;
    int digits = 0;
    int spaces = 0;
    int puncts = 0 ;
    int others = 0;
    cout << "Enter the text to analysis, and enter @ to termniate input.\n";
    cin.get(ch);
    while(ch != '@')
    {
        if (isalpha(ch))
            ++chars;
        else if (isdigit(ch))
            ++digits;
        else if (isspace(ch))
            ++spaces;
        else if (ispunct(ch))
            ++puncts;
        else 
            ++others;
        cin.get(ch);
    }
    cout << "Chars: " << chars << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
    cout << "Puncts:"  << puncts << endl;
    cout << "Others: " << others << endl;
    return 0;
}