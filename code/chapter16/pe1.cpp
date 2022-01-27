// pe1.cpp -- test palindrome
#include <iostream>
#include <string>

std::string palindrome(const std::string & s);
bool is_palindrome(const std::string & s);
int main()
{
    using std::cout;
    using std::string;
    using std::cin;
    string input;
    cout << "Enter a word(quit to quit): ";
    while (cin >> input && input != "quit")
    {
        if (is_palindrome(input))
            cout << input << " is palindrome\n";
        else
            cout << input << " is not palindrome\n";
        cout << "Enter a word(quit to quit): ";
    }
    cout << "Done\n";
    return 0;
}

std::string palindrome(const std::string & s)       // get the palindrome of string s
{
    std::string result;
    int size = s.size();
    result = s;
    char temp;
    for (int i = 0, j = size-1; i < j; i++, j--)    // j should be size - 1
    {
        temp = s[i];
        result[i] = result[j];
        result[j] = temp;
    }
    return result;
}

bool is_palindrome(const std::string & s)
{
    return palindrome(s) == s;
}