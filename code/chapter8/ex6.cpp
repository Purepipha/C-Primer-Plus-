// ex6.cpp -- using template function and explicit template function to find max
#include<iostream>
#include<cstring>

template<class T>
T maxn(T[], int n);

template<>
char * maxn<char *>(char *ps[], int n);

template<class T>
void show(T[], int size);

int main()
{
    using namespace std;
    int size;
// test integer
    cout << "Enter the number of integer: ";
    cin >> size;
    int iar[size];
    cout << "Enter "<< size <<" integer value ，and I will find the max:\n";
    for(int i = 0; i < size; i++)
    {
        cout << "Value #" << i + 1 << ": ";
        cin >> iar[i];
    }
    cout << "The integer array:\n";
    show(iar,size);
    int imax = maxn(iar,size);
    cout << "The max value is " << imax << endl;

// test double
    cout << "Enter the number of double: ";
    cin >> size;
    double dar[size];
    cout << "Enter "<< size <<" double value ，and I will find the max:\n";
    for(int i = 0; i < size; i++)
    {
        cout << "Value #" << i + 1 << ": ";
        cin >> dar[i];
    }
    cout << "The double array:\n";
    show(dar,size);
    double dmax = maxn(dar,size);
    cout << "The max value is " << dmax << endl;
// test char *
    char temp[100];
    cout << "Enter the number of strings: ";
    cin >> size;
    char * ps[size];
    cout << "Enter "<< size <<" string value ，and I will find the address of max:\n";
    for(int i = 0; i < size; i++)
    {
        cout << "Strings #" << i + 1 << ": ";
        while(cin.get() == '\n')
            continue;
        cin.getline(temp,100);
        ps[i] = new char[strlen(temp)+1]; // is must else will cause the mistake,need to distribute RAM
        strcpy(ps[i],temp);
    }
    cout << "The String array:\n";
    show(ps,size);
    char * psmax = maxn(ps,size);
    cout << "The address of max length string is " << &psmax << endl;
    for(int i = 0; i < size; i++)
        delete [] ps[i];
    return 0;
}

template<class T>
T maxn(T arr[], int n)
{
    T max = arr[0];
    for(int i = 0; i < n; i++)
        max =  max > arr[i] ? max : arr[i];
    return max;
}

template<>
char * maxn<char *>(char *ps[], int n)
{
    char * max = ps[0];
    for(int i = 0; i < n; i++)
        max =  strlen(max) >= strlen(ps[i]) ? max : ps[i];
    return max;
}

template<class T>
void show(T arr[],int n)
{
    using std::cout;
    for(int i = 0; i < n; i++)
        cout << arr[i] << ",";
    cout << "\n";
}