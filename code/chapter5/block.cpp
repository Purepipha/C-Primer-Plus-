//block.cpp -- use a block statement
#include<iostream>
int main()
{
    using namespace std;
    cout << "The Amazing Accounto will sum and average ";
    cout << "five numbers for you.\n";
    cout << "Enter five values:\n";
    double number;
    double sum = 0;
    for(int i = 1;i <= 5;i++)
    {
        cout << "Value " << i << ": ";
        cin >> number;
        sum += number;
    }
    cout << "Five exquisite choices indeed! ";
    cout << "They are sum to " << sum << endl;
    cout << "and average to " << sum/5.0 << endl;
    return 0;

}