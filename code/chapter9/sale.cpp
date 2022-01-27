// sale.cpp -- function definiation of sale
#include<iostream>
#include"sale.h"

static double find_min(const double ar[], int n);
static double find_max(const double ar[], int n);
static double average(const double ar[], int n);
static double * find_4less(const double ar[], int n);


namespace SALES
{
    void setSales(Sales & s, const double ar[], int n)
    {
        s.min = find_min(ar, n);
        s.max = find_max(ar, n);
        s.average = average(ar,n);
        if(n <= 4)
        {
            int i;
            for(i = 0; i < n; i++)
                s.sales[i] = ar[i];
            for(;i < 4; i++)
                s.sales[i] = 0;
        }
        else
        {
            for(int i = 0; i < 4; i++)
                s.sales[i] = find_4less(ar, n)[i];
        }
    
    }

    void setSales(Sales & s)
    {
        using std::cout;
        using std::cin;
        cout << "Enter four sales:\n";
        for(int i = 0; i < 4; i++)
        {
            cout << "Sales #" << i + 1 << ": ";
            cin >> s.sales[i];
        }

        s.min = find_min(s.sales, 4);
        s.max = find_max(s.sales, 4);
        s.average = average(s.sales, 4);
    }

    void showSales(const Sales & s)
    {
        using std::cout;
        cout << "Sales list:\n";
        for(int i = 0; i < 4; i++)
        {
            cout << "Sales #" << i + 1 << ": ";
            cout << s.sales[i] << "\t";
        }
        cout << "\n";
        cout << "Average = " << s.average << ", max = " << s.max;
        cout << ", min = " << s.min << "\n";
    }


}


double find_min(const double ar[], int n)
{
    double min = ar[0];
    for(int i = 0; i < n; i++)
        min = min < ar[i] ? min : ar[i];
    return min;
}

double find_max(const double ar[], int n)
{
    double max = ar[0];
    for(int i = 0; i < n; i++)
        max = max < ar[i] ? ar[i] : max;
    return max;
}

double average(const double ar[], int n)
{
    double sum = 0;
    for(int i = 0; i < n; i++)
        sum += ar[i];
    return sum / n;
}
static double * find_4less(const double ar[], int n)
{
    double * lesser4 = new double[4];
    double lesser;
    lesser4[0] = find_min(ar, n);
    for(int i = 1; i < 4; i++)
    {
        lesser = find_max(ar, n);
        for(int j = 0; j < n; j++)
        {
            if(ar[j] > lesser4[i-1])
                lesser = lesser < ar[j] ? lesser : ar[j]; 
        }
        lesser4[i] = lesser;
    }
    return lesser4;
}