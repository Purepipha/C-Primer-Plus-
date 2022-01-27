// topfive.cpp -- handling an array of string objects
#include<iostream>
#include<string>
const int SIZE = 5;
using namespace std;
void display(string ars[], int n);

int main()
{
    string list[SIZE];
    cout << "Enter your " << SIZE << " favourite astronomical sights:\n";
    for(int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << ": ";
        getline(cin,list[i]);
    }
    cout << "List:\n";
    display(list,SIZE);
    return 0;

}

void display(string ars[], int n)
{
    for(int i = 0; i < n; i++)
        cout << i + 1 << ": " << ars[i] << endl;
}