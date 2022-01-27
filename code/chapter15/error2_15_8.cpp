// error2_15_8.cpp -- return an error code
#include <iostream>
#include <cfloat>   // or float.h for DBL_MAX

bool hmean(double a, double b, double * ans);

int main()
{
    double x, y, z;

    std::cout << "Enter two numebrs: ";
    while (std:: cin >> x >> y)
    {
        if (hmean(x, y, &z))
            std::cout << "Harmonic is mean of " << x << " and " << y
                << " is " << z << std::endl;
        else
            std::cout << "One value should not be the negative "
                << "of the other - try again.\n";
        std::cout << "Enter next sey of numbers <q to quit>: ";
    }
    std::cout << "Bye!\n";
    return 0;
}

bool hmean(double a, double b, double * ans)
{
    if (a == -b)
    {
        * ans = DBL_MAX;
        return false;
    }
    else
    {
        * ans = 2 * a * b / (a + b);
        return true;
    }
}