// cmpstr1.cpp -- compare strings using arrays
#include<iostream>
#include<cstring>
int main()
{
    using namespace std;
    char w[5] = " ate";
    for(char ch='a';strcmp(w,"mate");ch++)
    {
        cout << w << endl;
        w[0] = char(ch); // w[0] = ch;
    }
    cout << "The word is " << w << endl;
    return 0;

}