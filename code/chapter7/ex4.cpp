// ex4.cpp -- cal the property of get number
#include<iostream>

long double cal_property(int r1, int n, int r2);

int main()
{
    using namespace std;
    int range1, range2, num;
    cout << "Enter the number of field number: ";
    cin >> range1;
    cout << "Enter the number of choose field number: ";
    cin >> num;
    cout << "Enter the number of specific number: ";
    cin >> range2;
    long double property = cal_property(range1, num, range2);
    cout << "The property of get money is one in " << property << endl;
    return 0;
}

long double cal_property(int r1, int n, int r2)
{
    long double result = 1.0;
    for(int i = r1,j = n; j > 0; i--, j--)
        result = result * i / j;
    result *= r2;
    return result;
}