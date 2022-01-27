// strtype3.cpp -- more string class features
#include<iostream>
#include<string>
#include<cstring>
int main()
{
    using namespace std;
    char charr1[20];
    char charr2[20] = "jaguar";
    string s1;
    string s2 = "panther";

    // assignment
    s1 = s2;
    strcpy(charr1,charr2);

    // appending
    s1 += " paste";
    strcat(charr1," juice");

    // the length
    int len1 = s1.size();
    int len2 = strlen(charr1);

    cout << "The string " << s1 << " contains " 
         << len1 << " characters.\n";
    cout << "The string " << charr1 << " contains"
         << len2 << " characters.\n";
         return 0;


}