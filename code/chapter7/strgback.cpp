// strgback.cpp -- a function that return a pointer to char
#include<iostream>
#include<string>
char * buildstr(char ch, int m);

int main()
{
    using namespace std;
    char c;
    int n;
    cout << "Enter a char: ";
    cin >> c;
    cout << "Enter a number: ";
    cin >> n;
    // string str = buildstr(c,n);
    // cout << "The build str is " << str << ".\n";
    char *ps = buildstr(c,n);
    cout << ps << endl;
    ps = buildstr('+',20);
    cout << ps <<"DONE" << ps << endl;
    delete []ps;
    return 0;
}
char *buildstr(char ch, int m)
{
    char * pt = new char[m+1];
    for( int i = 0; i < m; i++)
        pt[i] = ch;
    *(pt + m) = '\0'; // must
    return pt;
}