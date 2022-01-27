// ex6.cpp -- using function to deal with array
#include<iostream>

const int Size = 5;
int Fill_array(double [], int len);
void Show_array(double arr[], int len);
void Reverse_array(double *, int len);
int main()
{
    using namespace std;
    double grade[Size];
    int len = Fill_array(grade, Size);
    Show_array(grade, len);
    Reverse_array(grade, len);
    cout << "Reverse array:\n";
    Show_array(grade, len);
    Reverse_array(grade + 1, len -2);
    cout << "Reverse part of array:\n";
    Show_array(grade,len);
    return 0;
}

int Fill_array(double arr[], int len)
{
    using namespace std;
    int count = 0;
    cout << "Enter a number(enter q to quit): ";
    while(cin >> arr[count])
    {
        count++;
        if(count >= len)
            break;
        cout << "Enter next number(enter q to quit): ";
    }
    return count;
}

void Show_array(double arr[], int len)
{
    using namespace std;
    for(int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Reverse_array(double *par, int len)
{
    double temp;
    for(int i = 0, j = len-1; i < j; i++,j--)
    {
        temp = par[i];
        par[i] = par[j];
        par[j] = temp;
    }
}