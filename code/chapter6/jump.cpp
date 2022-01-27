// jump.cpp -- using continue and break
#include<iostream>
const int Arsize = 80;
int main()
{
    using namespace std;
    char text[Arsize];
    int spaces = 0;
    cout << "Enter a line of text: \n";
    cin.getline(text, Arsize);
    cout << "Complete line: " << text << endl;
    cout << "deal with line: ";
    for(int i = 0; text[i] != '\0'; i++)
    {
        cout << text[i];
        if(text[i] == '.')
            break;
        if(text[i] != ' ')
            continue;
        ++spaces;
    }
    cout << endl << spaces << " spaces.\n";
    cout << "Done\n";
    return 0;
}