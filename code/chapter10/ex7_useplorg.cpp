// ex7_useplorg.cpp -- test class Plorg
// compile with plorg.cpp

#include <iostream>
#include <cstring>
#include "plorg.h"

const int PSize = 10;
int main()
{
    using std::cout;
    using std::cin;
    Plorg plorg[PSize];
    Plorg pl = Plorg("Jobs Sam",60);
    pl.ShowPlorg();
    char name[NSIZE];
    int CI;
    int count = 0;
    for(int i = 0; i < PSize; i++)
    {
        cout << "The plorg #" << i + 1 << ":\n";
        cout << "Enter the name(enter empty string to quit): ";
        cin.getline(name, NSIZE);
        if(!strcmp(name,""))
            break;
        count++;
        cout << "Enter the CI: ";
        while(!(cin >> CI)) // () is must
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Bad input, please input a integer: ";
        }
        cin.get();
        plorg[i].setname(name);
        plorg[i].setCI(CI);
    }
    cout << "Plorg List:\n" ;
    for(int i = 0; i < count; i++)
        plorg[i].ShowPlorg();

    cout << "Bye\n";

}