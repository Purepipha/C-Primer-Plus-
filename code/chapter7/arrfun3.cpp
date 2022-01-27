// arrfun3.cpp -- array functions and const
#include<iostream>
const int Max = 5;

int fill_arr(double ar[], int limit);
void show_arr(const double ar[], int n);
void revalue(double r, double ar[], int n);

int main()
{
    using namespace std;
    double property[Max];

    int size = fill_arr(property, Max);
    show_arr(property, size);
    if(size > 0)
    {
        cout << "Enter the revaluation facctor: ";
        double factor;
        while(!(cin >> factor))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, property, size);
        show_arr(property, size);
    }
    cout << "Done.\n";
    cin.get();
    cin.get();
    return 0;
}

int fill_arr(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for(i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << " : ";
        cin >> temp;
        if(!cin)
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if(temp < 0)
            break;
        ar[i] = temp;
    }
    return i;
}

void show_arr(const double ar[], int n)
{
    for(int i = 0; i < n; i++)
        std::cout << "Property #" << (i + 1) 
                  << " : $" << ar[i] << std::endl;
}

void revalue(double r, double ar[], int n)
{
    for(int i = 0; i < n; i++)
        ar[i] *= r;
}