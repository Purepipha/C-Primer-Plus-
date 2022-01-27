// leftover8_10.cpp -- overloading the left() function
#include<iostream>
#include<cstring>
unsigned long left(unsigned long num, unsigned ct);
char * left(const char * str, int n = 1);
int main()
{
    using namespace std;
    const char * trip = "Hawaii!!";
    unsigned long n = 12345678;
    int i;
    char * temp;
    for (i = 0; i < 10; i++)
    {
        cout << left(n, i) << endl;
        temp = left(trip, i);
        cout << temp << endl;
        delete [] temp;
    }
    return 0;

}

unsigned long left(unsigned long num, unsigned ct)
{
    int digits = 1;
    unsigned long result;
    result = num;
    while(num /= 10)
        digits++;
    
    if(digits > ct)
    {
        ct = digits - ct;
        while(ct--)
            result /= 10;
    }
    return result;
}
char * left(const char * str, int n)
{
    char * ts;
    if(n < 0)
        return ts; //n=0;
    int i;
    n = (n < strlen(str)) ? n : strlen(str); //
    ts = new char[n + 1];
    for(i = 0; i < n && str[i]; i++)
    {
        ts[i] = str[i];
    }
    ts[n] = '\0';
    return ts;
}