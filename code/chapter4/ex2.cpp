#include<iostream>
#include<string>
int main()
{
    using namespace std;
    string name;
    string dessert;

    cout << "Enter your name:\n";
    // input a line need to use getline,cin >> will wrong.
    getline(cin,name);
    cout << "Enter your favourite dessert:\n";
    getline(cin,dessert);
    cout << "I have some delicious "<< dessert;
    cout << " for you, " << name << endl;
    return 0;
}