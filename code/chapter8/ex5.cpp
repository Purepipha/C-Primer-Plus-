// ex5.cpp -- using template funtion to find the max
#include<iostream>
const int Size = 5;

template<class T>
T max5(T[]);

template<class T>
void show(T[]);

int main()
{
    using namespace std;
    int iar[Size];
    double dar[Size];
    // integer
    cout << "Enter five integer，and I will find the max:\n";
    for(int i = 0; i < Size; i++)
    {
        cout << "Integer #" << i + 1 << ": ";
        cin >> iar[i];
    }
    cout << "The integer array:\n";
    show(iar);
    int imax = max5(iar);
    cout << "The max value is " << imax << endl;
    // double
    cout << "Enter five double values，and I will find the max:\n";
    for(int i = 0; i < Size; i++)
    {
        cout << "Value #" << i + 1 << ": ";
        cin >> dar[i];
    }
    cout << "The double array:\n";
    show(dar);
    double dmax = max5(dar);
    cout << "The max value is " << dmax << endl;
    return 0;
    
}

template<class T>
T max5(T arr[])
{
    T max = arr[0];
    for(int i = 0; i < Size; i++)
        max =  max > arr[i] ? max : arr[i];
    return max;
}

template<class T>
void show(T arr[])
{
    using std::cout;
    for(int i = 0; i < Size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}