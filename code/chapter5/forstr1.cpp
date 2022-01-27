#include<iostream>
#include<string>
int main()
{
    using namespace std;
    string word;
    cout << "Enter a word: ";
    cin >> word;
    for(int i = word.size();i>=0; i--)
        cout << word[i];
    cout << "\nBye.\n";
    return 0;
}