// arrobj.cpp -- functions with array objects(C++11)
#include<iostream>
#include<array>
#include<string>

using namespace std;

const int Seasons = 4;
const array<string,Seasons>Sname = 
{"Spring", "Summer", "Fall", "Winter"};

void show(array<double,Seasons> & arr);
void fill(array<double,Seasons> & arr);

int main()
{
    array<double, Seasons> expense;
    fill(expense);
    cout << "Your expense list:\n";
    show(expense);
    return 0;
}

void show(array<double,Seasons> & arr)
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << Sname[i] << ": " << arr[i] << endl;
    }
}

void fill(array<double,Seasons> & arr)
{
    double temp;
    int count = 0;
    cout << "Enter your expense of every season, enter q to quit.\n";
    while(count < Seasons)
    {
        cout << Sname[count] << ": " ;
        cin >> temp;
        if(!cin)
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Bad input, process will terminated.";
            break;
        }
        else if(temp < 0)
            break;
        arr[count] = temp;
        count ++;
    }
}