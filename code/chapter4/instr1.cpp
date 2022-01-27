// instr1.cpp - - reading more than one string
#include<iostream>
int main()
{
    using namespace std;
    const int arsize = 20;
    char name[arsize];
    char dessert[arsize];
    cout << "What's your name:\n";
    cin >> name;
    cout << "Enter your favourite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << endl;
    return 0;

}