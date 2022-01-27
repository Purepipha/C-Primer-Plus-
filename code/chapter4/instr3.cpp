// instr3.cpp - - reading more than one string with get() & get()
#include<iostream>
int main()
{
    using namespace std;
    const int arsize = 20;
    char name[arsize];      
    char dessert[arsize];
    cout << "What's your name:\n";
    cin.get(name, arsize).get();
    cout << "Enter your favourite dessert:\n";
    cin.get(dessert,arsize).get();
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << endl;
    return 0;
}
