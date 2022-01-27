// ex1.cpp -- read the key input
#include<iostream>
#include<cctype>
int main()
{
    using namespace std;
    char ch;
    cout << "Enter the text, type @ to terminate.\n";
    while((ch = cin.get()) && ch != '@')
    {
        if(isdigit(ch))
        {
            continue; //is continue not break
        }
            
        else if(islower(ch))
            cout << char(toupper(ch));
        else if(isupper(ch))
            cout << char(ch + 32);
        else 
            cout << ch; 
        //ch = cin.get();   
    }
    return 0;
}