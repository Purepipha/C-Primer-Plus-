// ex4.cpp -- using
#include<iostream>
using namespace std;
const int strsize = 30;
const int Arrsize = 5;
struct bop{
    char fullname[strsize];//real name
	char title[strsize];
	char bopname[strsize];
	int preference;
};

const bop arrbop[Arrsize] //how to use bop *  本来就是常量
    {
        {"Wimp Macho", "Beginner Programmer", "WMU", 0},
        {"Raki Rhodes", "Junior Programmer", "RRA", 1},
        {"Celia Laiter", "Beginner Programmer", "MIPS", 2},
        {"Hoppy Hipman", "Analyst Trainee", "HHP", 1},
        {"Pat Hand", "Junior Programmer", "LOOPY",2} 
    };

void show_choice();
void disp_name();
void disp_title();
void disp_bopname();
void disp_perference();

int main()
{

// init bop 
    char ch;
    show_choice();
    cout << "Enter your choice: ";
    cin >> ch;
    while(ch != 'q')
    {
        switch(ch)
        {
            case 'a': disp_name(); break;
            case 'b': disp_title(); break;
            case 'c': disp_bopname(); break;
            case 'd': disp_perference();break;
            default : cout << "Please enter correct char.\n";break;
        }
        cout << "Next choice: ";
        cin >> ch;
    }
    cout << "Bye!\n";
    return 0;
}
void show_choice()
{
    cout << "Benevolent Order of Programmers Report\n"
            "a. display by name         b. display by title\n"
            "c. display by bop name	    d. display by preference\n"
            "q. quit\n";
}

void disp_name()
{
    for(int i = 0; i < Arrsize; i++)
        cout << arrbop[i].fullname << endl;
}

void disp_title()
{
    for(int i = 0; i < Arrsize; i++)
        cout << arrbop[i].title << endl;
}

void disp_bopname()
{
    for(int i = 0; i < Arrsize; i++)
        cout << arrbop[i].bopname << endl;
}

void disp_perference() // function name wirte correct
{
    for(int i = 0; i < Arrsize; i++)
        switch(arrbop[i].preference)
        {
            case 0 : cout << arrbop[i].fullname << endl;break;
            case 1 : cout << arrbop[i].title << endl;break;
            case 2 : cout << arrbop[i].bopname << endl;break;
            default: break;
        }
}