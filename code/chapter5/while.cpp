// while.cpp -- introduce the while loop
#include<iostream>
const int arsize = 20;
int main()
{
    using namespace std;
    char name[arsize];
    cout << "Enter your first name: ";
    cin >> name;
    cout << "Here is your name verticalized and ASCIIized:\n";
    int i = 0;
    while (name[i] != '\0')//while(name[i])
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;
    }
    return 0;
}