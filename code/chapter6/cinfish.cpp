// cinfish.cpp -- non-numeric input terminates loop
#include<iostream>
const int Max = 5;
int main()
{
    using namespace std;
    double fish[Max];
    cout << "Please enter the weight of your fish: \n";
    cout << "You may enter up to " << Max
         << " fish <q to terminate>.\n";
    int i = 0;
    cout << "fish #1: ";
    while(i < Max && cin >> fish[i])
    {
        if(++i < Max)
            cout << "fish #" << i + 1 << ": ";
    }
    double total = 0;
    for (int j = 0; j < i; j++)
        total += fish[j];
    if (i == 0)
        cout << "No,fish.\n";
    else  
        cout << total / 5 << " = average weight of "
             << i << " fish\n";
    cout << "Done.\n";
    return 0;
}