// ex3.cpp -- convert the a... to A...
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
void str_toupper(string & s);

int main()
{
    string s;
    cout << "Enter a string(q to quit): ";
    getline(cin,s);
    while(s != "q")
    {
        str_toupper(s);
        cout << s << endl;
        cout << "Next string(q to quit): ";
        getline(cin,s);
    }
    cout << "Bye.\n";
    return 0;
}

void str_toupper(string & s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        s[i] = toupper(s[i]);
        i++;
    }
}