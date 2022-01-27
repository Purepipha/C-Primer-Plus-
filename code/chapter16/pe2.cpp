// pe2.cpp -- test palindrome
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

bool notalpha(char ch) { return !isalpha(ch); }     // is not alpha
char toLower(char ch) { return tolower(ch); }       // ch to lower
std::string ToLower(const std::string & s);                      // string to lower
std::string predeal(const std::string & s);                      // delete not alpha and ToLower
std::string palindrome(const std::string & s);
bool is_palindrome(const std::string & s);

int main()
{
    using std::cout;
    using std::string;
    using std::cin;
    string input;
    cout << "Enter a line of string (quit to quit): ";
    while (getline(cin, input) && input != "quit")
    {
        string deal_s = predeal(input);
        if (is_palindrome(deal_s))
            cout << input << " is palindrome\n";
        else
            cout << input << " is not palindrome\n";
        cout << "Enter a line of string (quit to quit): ";
    }
    cout << "Done\n";
    return 0;
}

std::string ToLower(const std::string & s)
{
    std::string temp;
    for (int i = 0; i < s.size(); i++)
        temp[i] = toLower(s[i]);
    return temp;
}
std::string predeal(const std::string & s)
{
    std::string deal_result;
    deal_result = s;
    auto end_ir = remove_if(deal_result.begin(), deal_result.end(),notalpha);
    deal_result.erase(end_ir, deal_result.end());
    return ToLower(deal_result);
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