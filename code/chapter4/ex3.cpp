//ex3.cpp -- input your name
#include<iostream>
#include<cstring>
int main()
{
    using namespace std;
    char first_name[20];
    char last_name[20];
    char name[40];
    cout << "Enter your first name: ";
    cin.getline(first_name, 20);
    cout << "Enter your last name: ";
    cin.getline(last_name,20);
    strcpy(name,last_name);
    strcat(name,", ");
    strcat(name,first_name);
    cout << "Here's the information in a single string: ";
    cout << name << endl;
    return 0;
}