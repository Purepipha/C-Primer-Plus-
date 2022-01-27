// instr2.cpp - - reading more than one string with getline
#include<iostream>
int main()
{
    using namespace std;
    const int arsize = 20;
    char name[arsize];
    char dessert[arsize];
    cout << "What's your name:\n";
    cin.getline(name, arsize);
    cout << "Enter your favourite dessert:\n";
    cin.getline(dessert,arsize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << endl;
    return 0;

}