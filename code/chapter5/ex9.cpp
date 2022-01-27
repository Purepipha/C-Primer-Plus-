// ex9.cpp -- get the number of enter words by using string
#include<iostream>
#include<string>
int main()
{
    using namespace std;
    string word; 
    int count = 0;
    int i = 0;
    cout << "Enter words(to stop, type the word done): \n";
    cin >> word;
    while(word != "done")
    {
        cin >> word;
        count++;
    }
    cout << "You entered a total of " << count << " words.\n";
    return 0;
}
