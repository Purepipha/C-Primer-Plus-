// error3_15_9.cpp -- using an exception
#include <iostream>
double hmean(double a, double b);

int main()
{
    double x, y, z;

    std::cout << "Enter two numebrs: ";
    while (std::cin >> x >> y)
    {
        try{                    // start of try block
            z = hmean(x, y);
        }                       // end of try block
        catch (const char * s)  // start of exception handler
        {
            std::cout << s << std::endl;
            std::cout << "Enter a new pair of number: ";
            continue;
        }
        std::cout << "Harmonic is mean of " << x << " and " << y
            << " is " << z << std::endl;
        std::cout << "Enter next sey of numbers <q to quit>: ";
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw "bad hmean() arguments: a = -b not allowed";
    return 2.0 * a * b / (a + b);
}