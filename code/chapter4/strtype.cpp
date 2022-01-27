// strtype.cpp -- using the c++ string class
#include<iostream>
#include<string>   //make string class available
int main()
{
    using namespace std;
    char char1[20];
    char char2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    cout << "Enter a kind of feline: ";
    cin >> char1;
    cout << "Enter another kind of feline: ";
    cin >> str1;
    cout << "Here are some felines:\n";
    cout << char1 << " " << char2 << " "
         << str1 << " " << str2 << endl;
    cout << "The third letter in " << char2 << " is "
         << char2[2] << endl;
    cout << "The third letter in " << str2 << " is "
         << str2[2] <<endl;
    return 0;
}
