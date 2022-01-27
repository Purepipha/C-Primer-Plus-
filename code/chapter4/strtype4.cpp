// strtype.cpp -- line input
#include<iostream>
#include<string>
#include<cstring>
int main()
{
    using namespace std;
    char charr[20];
    string s;
    cout << "Length of string charr before input: "
         << strlen(charr) << endl;
    cout << "Length of string s before input: "
         << s.size() << endl;
    cout << "Enter a line of text: \n";
    cin.getline(charr,20);
    cout << "You entered: " << charr << endl;
    cout << "Enter anthoer line of text: \n";
    getline(cin,s);
    cout << "You entered: " << s << endl;
    cout << "Length of string in charr after input: "
         << strlen(charr) << endl;
    cout << "Length of string in s after input: "
         << s.size() << endl;
    cout << R"+=("(who wouldn't)",she whispered.)+="; // +=作为界符
    return 0;
}