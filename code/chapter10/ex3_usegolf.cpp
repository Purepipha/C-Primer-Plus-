// ex3_usegolf.cpp -- test class Golf
// compile with golf.cpp
#include <iostream>
#include "golf.h"

const int Arsize = 5;
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    int hd, number;
    int count = 0;
    Golf gar[Arsize];
    cout << "Enter the Users' name and level(enter empty string to name to quit):\n";
    for(int i = 0; i < Arsize; i++)
    {
        cout << "User #" << i + 1 << ":\n";
        int end_flag = gar[i].setgolf();
        if (end_flag == 0)
            break;
        count++;
    }
    for(int i = 0; i < count; i++)
    {
        cout << "User #" << i + 1 << ":\t";
        gar[i].Show();
    }
    // using handicap
    
    cout << "Enter the number of user you need to change level(q to quit): ";
    while(cin >> number)
    {
        cout << "The new Level: ";
        cin >> hd;
        gar[number - 1].set_handicap(hd);
        cout << "Enter next number(q to quit): "; 
    }
    cout << "The new golf users list:\n";
    for(int i = 0; i < count; i++)
    {
        cout << "User #" << i + 1 << ":\t";
        gar[i].Show();
    }
    cout << "Bye\n";
    return 0;
}