// forstr2.cpp -- reversing an array
#include<iostream>
#include<string>
int main()
{
    using namespace std;
    char temp;
    string word;
    cout << "Enter a word: ";
    cin >> word;
    for(int i = 0, j = word.size()-1;i<=j;i++,j--)
    {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    cout << "The reversing result: "<< word;
    return 0;
}