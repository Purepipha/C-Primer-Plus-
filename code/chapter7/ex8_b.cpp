// ex8_b.cpp -- functions with double structure(C++11)
#include<iostream>
#include<string>

const int Seasons = 4;
const char* Sname[Seasons] = 
{"Spring", "Summer", "Fall", "Winter"};

struct Expense
{
    double expense[Seasons];
};

using namespace std;




void fill(double *,int n);
void show(double [], int);

int main()
{
    Expense ex;
    fill(ex.expense, Seasons);
    cout << "Your expense list:\n";
    show(ex.expense,Seasons);
    return 0;
}

void fill(double *pta, int n)
{
    double temp;
    int count = 0;
    cout << "Enter your expense of every season, enter q to quit.\n";
    while(count < n)
    {
        cout << *(Sname + count) << ": " ;
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
        *(pta + count) = temp;
        count ++;
    }
}

void show(double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << Sname[i] << ": " << arr[i] << endl;
    }
}