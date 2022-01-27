// pe3.cpp -- variadic template
#include <iostream>
#include <iomanip>

template<typename T, typename... Args>
long double sum_value(T value, Args... args);

long double sum_value() { return 0.0; }

int main()
{
    using std::cout;
// list of int and double and char
    auto q = sum_value(1, 2, 9.6, 'a', 10);
    cout << std::fixed << std::setprecision(4);
    cout << q << std::endl;
    auto sum = sum_value('!', 345, 333,'A');
    cout << sum << std::endl;
    return 0;
}

template<typename T, typename... Args>
long double sum_value(T value, Args... args)
{
    return value + sum_value(args...);
}