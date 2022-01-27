// ex2.cpp -- using a static local variable and using string
#include<iostream>
#include<string>
// constants
const int ArSize = 10;
// function prototype
void strcount(const std::string str);

int main()
{
    using namespace std;
    string input;
    char next;

    cout << "Enter a line:\n";
    getline(cin, input);
    while(cin)
    {   if(input == "")
            break;
        strcount(input);
        cout << "Enter next line(empty line to quit):\n";
        getline(cin, input);
    }
    cout << "Bye\n";
}

void strcount(const std::string str)
{
    using namespace std;
    static int total = 0;
    int count = 0;

    cout << "\"" << str << "\" contains ";
    while(str[count])
    {
        count++;
    }
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}