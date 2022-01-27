// variadic2_18_10.cpp
#include <iostream>
#include <string>

// definition for 0 parameters
void show_list() {}

// definotion for 1 parameters
template<typename T>
void show_list(T value) 
{
    std::cout << value << '\n';
}

// definition for 2 or more paraters
template<typename T, typename...Arg>
void show_list(T value, Arg... arg)
{
    std::cout << value << ", ";
    show_list(arg...);
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    show_list(n, x);
    show_list(x * x, '!', 7, mr);
    return 0;
}