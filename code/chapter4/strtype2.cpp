// strtype2.cpp -- assigning, adding, and appending
#include<iostream>
#include<string>
int main()
{
    using namespace std;
    string str1 = "penguin";
    string str2, str3;
    cout << "You can assign one string object to another: s2 = s1\n";
    str2 = str1;
    cout << "str1: " << str1 << ", str2: " << str2 << endl;
    cout << "str2 = \"buzzard\"\n";
    str2 = "buzzard";
    cout << "str2: " << str2 << endl;
    str3 = str1 + str2;
    cout << "str3: " << str3 << endl;
    cout << "You can append strings.\n";
    str1 += str2;
    cout << "str1 += str2 yields str1 = " << str1 << endl;
    str2 += " for a day";
    cout << "str2 += \" for a day\" yield str2 = " << str2 << endl; 
    return 0;

}