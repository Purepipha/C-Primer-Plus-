//ex7.cpp -- array functions and point
#include<iostream>
const int Max = 5;

double * fill_arr(double *, double *);
void show_arr(double *, double *);
void revalue(double r, double *, double *);

int main()
{
    using namespace std;
    double property[Max];

    double * ptend = fill_arr(property, property + Max);
    show_arr(property, ptend);
    if(ptend - property > 0)
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
        revalue(factor, property, ptend);
        show_arr(property, ptend);
    }
    cout << "Done.\n";
    cin.get();
    cin.get();
    return 0;
}

double * fill_arr(double * begin, double * end)
{
    using namespace std;
    double temp;
    double * pt;
    int count = 0;
    for(pt = begin; pt != end; pt++)
    {
        cout << "Enter value #" << (count + 1) << " : ";
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
        *pt = temp;
        count++;
    }
    return pt;
}

void show_arr(double * begin, double * end)
{
    double *pt;
    int i = 0;
    for(pt = begin; pt != end; pt++)
        std::cout << "Property #" << (i + 1) 
                  << " : $" << *pt << std::endl;
    i++;
}

void revalue(double r, double * begin, double * end)
{
    double *pt;
    for(pt = begin; pt != end; pt++)
        *pt *= r;
}