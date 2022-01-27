// ex8.cpp -- get the number of enter words
#include<iostream>
#include<cstring>
int main()
{
    using namespace std;
    char temp[20]; 
    int count = 0;
    int i = 0;
    cout << "Enter words(to stop, type the word done): \n";
    cin >> temp;
    while(strcmp(temp,"done"))
    {
        // cin >> temp[i];
        // while(temp[i] != ' ')
        // {
        //     i++;
        //     cin >> temp[i];
        // }
        // i = 0;
        cin >> temp;
        count++;
    }
    cout << "You entered a total of " << count << " words.\n";
    return 0;
}
// 找一下cin>>字符串的内容
