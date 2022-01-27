// ex2.cpp -- calculate avergage
#include<iostream>
const int Max = 10;

int main ()
{
    using namespace std;
    int count = 0;
    double donation[Max];
    double sum = 0, average;
    int cnt_ab = 0;
    cout << "Enter the donation value, type char to terminate.\n";
    cout << "Value #" << count + 1 << ": ";
// get value
    while (cin >> donation[count])
    {
        sum += donation[count];// calculate sum
        if(++count < Max) //v1: ++count <= Max
        {
            cout << "Value #" << count + 1 << ": ";
        }
        else 
            break;      
    }
//
    average = sum / count;
    cout << "The average of " << count << " value is " << average << endl;

    for(int i = 0; i < count; i++)
    {
        if(donation[i] > average)
            cnt_ab++;
    }
    cout << "The number of value over average is " << cnt_ab << endl;
    return 0;
}