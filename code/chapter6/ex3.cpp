// ex3.cpp -- write a model of memu
#include<iostream>
using namespace std;
void showmenu();
int main()
{
    char ch;
    showmenu();
    cout << "please enter a c, p, t, or g: ";
    cin >> ch;
    while(ch != 'f')
    {
        switch(ch)
        {
            case 'c':
            case 'C': cout << "It's a carnivore.\n"; break;
            case 'p':
            case 'P': cout << "He is a pianist.\n"; break;
            case 't':
            case 'T': cout << "A maple is a tree.\n"; break;
            case 'g':
            case 'G': cout << "The game is funning.\n"; break;
            default : cout << "Please enter a correct char.\n";break;
        }
        cout << "please enter a c, p, t, or g: ";
        cin >> ch; // first forget to wirte
    }
}
void showmenu()
{
    cout << "Please enter one of the following choices:\n"
            "c) carnivore               p)pianist\n"
            "t) tree                    g)game\n"
            "f\n";
}