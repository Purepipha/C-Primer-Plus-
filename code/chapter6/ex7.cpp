// ex7.cpp -- get the words class
#include<iostream>
#include<string>
#include<cctype>
int main()
{
    using namespace std;
    string word;
    int cnt_vowel = 0;
    int cnt_consonants = 0;
    int cnt_others;
    cout << "Enter words(q to quit): \n";
    cin >> word;
    while (word != "q")
    {
        if(isalpha(word[0]))
        {
            switch(word[0])
            {
                case 'a' :
                case 'A' :
                case 'e' :
                case 'E' :
                case 'i' :
                case 'I' :
                case 'o' :
                case 'O' :
                case 'u' :
                case 'U' : ++cnt_vowel;break;
                default: ++ cnt_consonants;break;
            }
        }
        else
            ++cnt_others;
            cin >> word;
    }
    cout << cnt_vowel << " words beginning with vowels\n";
    cout << cnt_consonants << " words beginning with consonants\n";
    cout << cnt_others << " others\n";
    return 0;
}