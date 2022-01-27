// dowhile.cpp -- exit-condition loop
#include<iostream>
int main()
{
    using namespace std;
    int num;
    cout << "Enter the numbers in the range 1-10 to find ";
    cout << "my favourite number\n";
    do
    {
        cin >> num;
    } while (num != 7);
    cout << "Yes, my favourite number is " << num;
    return 0;
    
}