// and.cpp -- using the logical AND operator
#include<iostream>
const int Arsize = 6;
int main()
{
    using namespace std;
    float naaq[Arsize];
    cout << "Enter the NAAQs(New Age Awareness Quotients)"
         << "of\nyour neighbors. Program terminates "
         << "when you make\n" << Arsize << " entries "
         << "or enter a negative value.\n";
    
    int i =0;
    float temp;
    cout << "First value: ";
    cin >> temp;
    while(i < Arsize && temp >= 0)
    {
        naaq[i] = temp;
        ++i;
        if(i < Arsize)
        {
            cout << "Next value: ";
            cin >> temp;
        }
    }
    if (i == 0)
        cout << "No data--bye\n";
    else
    {
        cout << "Enter your NAAQ: ";
        float you;
        cin >> you;
        int count = 0;
        for(int j = 0; j > i; j++)
            if(naaq[j] > you)
                ++count;
        cout << count;
        cout << " of your neighbors have greater awareness of\n"
             << "the New Age than you do.\n";
    }
    return 0;
}