// ifelse.cpp -- using if else statement
#include<iostream>
int main()
{
    using namespace std;
    char ch;
    cout << "Type, and I will repeat.\n";
    ch = cin.get();
    while(ch != '.')
    {
        if(ch == '\n')
            cout << ch;
        else
            cout << ++ch;  // ch+1 输出字符的编码+1
        cin.get(ch);
    }
    return 0;
}