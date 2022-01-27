// main_ex1.cpp -- using golf.cpp's function 
#include<iostream>
#include"golf.h"

const int Arsize = 5;
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    char name[Len];
    int hd, number;
    int count = 0;
    golf gar[Arsize];
    cout << "Enter the Users' name and level(enter empty string to name to quit):\n";
    for(int i = 0; i < Arsize; i++)
    {
        cout << "User #" << i + 1 << ":\n";
        int end_flag = setgolf(gar[i]);
        if (end_flag == 0)
            break;
        count++;
    }
    for(int i = 0; i < count; i++)
    {
        cout << "User #" << i + 1 << ":\t";
        showgolf(gar[i]);
    }
    // using handicap
    
    cout << "Enter the number of user you need to change level(q to quit): ";
    while(cin >> number)
    {
        cout << "The new Level: ";
        cin >> hd;
        handicap(gar[number - 1], hd);
        cout << "Enter next number(q to quit): "; 
    }
    cout << "The new golf users list:\n";
    for(int i = 0; i < count; i++)
    {
        cout << "User #" << i + 1 << ":\t";
        showgolf(gar[i]);
    }
    cout << "Bye\n";
    return 0;
}