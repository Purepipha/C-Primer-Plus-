// ifelseif.cpp 
#include<iostream>
const int Fave = 32;
int main()
{
    using namespace std;
    int n;
    cout << "Enter an number in the rang 1-100 to find ";
    cout << "my favourite number: ";
    do
    {
        cin >> n;
        if(n > Fave)
            cout << "Too high. -- guess again";
        else if(n < Fave)
                cout << "Too Low. -- guess again";
            else
                cout << n << " is right.\n";

    } while (n != Fave);
    return 0;
}